﻿#include "App.h"
#include "ConsoleGui.h"
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

App::~App()
{
   delete gui;
}

App::App()
{
   gui= new ConsoleGui;
}

DWORD WINAPI threadSimulator(LPVOID p)
{
   int planeOnLand= reinterpret_cast<int>(p);
   Simulator s;
   s.run(planeOnLand);
   return 0;
}

void App::startSimulator()
{
   int planesOnLand= gui->getPlanesOnLand();
   CreateThread(nullptr, 0, threadSimulator, &planesOnLand, 0, nullptr);
}

void App::run()
{
   startSimulator();
   bool keep;
   do {
      keep= executeCmd( gui->getMenuOption() );               
   } while (keep);
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
      case CLS: gui->clearDisplay();                        return new CmdIdle();
      case EXIT:                                            return new CmdRemoveData();
      default: gui->showMessage("error: Invalid input \n"); return new CmdIdle();   
   }
   
}

