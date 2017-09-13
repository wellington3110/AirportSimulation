#include "App.h"
#include "Gui.h"
#include "Console.h"
#include "Command.h"
#include "CmdLandingsNumber.h"
#include "CmdPlanesOnLandNumber.h"
#include "CmdPlanesWaitingNumber.h"
#include "CmdWindChangesHistoric.h"
#include "CmdPlanesWaitingGreaterThanFiveHistoric.h"
#include "CmdPlanesOnLandExceededCapacityHistoric.h"
#include "CmdPlanesSentAnotherAirportHistoric.h"
#include "CmdTakeOffRequestGreaterThanFiveHistoric.h"
#include "CmdIdle.h"
#include "Simulator.h"
#include <Windows.h>

#include "CmdRemoveData.h"
#include "CmdToListUnreadEvents.h"

App::~App()
{
   delete gui;
   delete Simulator::getInstance();
}

App::App()
{
   gui= new Gui(this);
}

DWORD WINAPI threadSimulator(LPVOID param)
{
   int planesOnLand= int(param);
   Simulator::getInstance()->run(planesOnLand);
   return 0;
}

void App::startSimulator()
{
   int planesOnLand= gui->getPlanesOnLand();
   CreateThread(nullptr, 0, threadSimulator, (void*)planesOnLand, 0, nullptr);
}

void App::run()
{
   startSimulator();
   if( dynamic_cast<Gui*>(gui) )
      gui->getMenuOption();
   else {
      bool keep;
      do {
         keep= executeCmd( gui->getMenuOption() );               
      } while (keep);
   }
}

bool App::executeCmd(int option)
{
   auto* cmdActual= createCmd(option);
   cmdActual->execute(gui);
   delete cmdActual;
   return option != EXIT ? true : false;      
}

Command* App::createCmd(int option)
{   
   switch (option) {
      case LANDED:                                          return new CmdLandingsNumber;
      case ON_LAND:                                         return new CmdPlanesOnLandNumber;
      case WAITING:                                         return new CmdPlanesWaitingNumber;
      case WIND_HISTORIC:                                   return new CmdWindChangesHistoric;
      case WAITING_GREATER_THAN_FIVE_HISTORIC:              return new CmdPlanesWaitingGreaterThanFiveHistoric;
      case EXCEEDED_CAPACITY_HISTORIC:                      return new CmdPlanesOnLandExceededCapacityHistoric;
      case SENT_ANOTHER_AIRPORT_HISTORIC:                   return new CmdPlanesSentAnotherAirportHistoric;
      case TAKE_OFF_REQUESTS_GREATER_THAN_FIVE:             return new CmdTakeOffRequestGreaterThanFiveHistoric;
      case LIST_UNREAD_EVENTS:                              return new CmdToListUnreadEvents;
      case CLS: gui->clearDisplay();                        return new CmdIdle();
      case EXIT: Simulator::getInstance()->stop();          return new CmdRemoveData();
      default: gui->showMessage("error: Invalid input \n"); return new CmdIdle();   
   }
}


