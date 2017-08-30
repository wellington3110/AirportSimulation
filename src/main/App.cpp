#include "App.h"
#include "ConsoleGui.h"
#include "ReportFactory.h"
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

App::~App()
{
   delete gui;
}

App::App()
{
   gui= new ConsoleGui;
   data= ReportFactory::getInstance();
}

void App::startSimulator()
{
   gui->showMessage("Número máximo de aviões em solo: ");
   int planesOnLand= gui->doInput();
   gui->clearDisplay();
   Simulator s;
   s.run(planesOnLand);
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
   if(cmdActual)
      cmdActual->execute(gui);
   else
      return false;
   delete cmdActual;
   return true;
}

Command* App::createCmd(int option)
{
   switch (option) {
      case LANDED:                                   return new CmdLandingsNumber;
      case ON_LAND:                                  return new CmdPlanesOnLandNumber;
      case WAITING:                                  return new CmdPlanesWaitingNumber;
      case WIND_HISTORIC:                            return new CmdWindChangesHistoric;
      case WAITING_GREATER_THAN_FIVE_HISTORIC:       return new CmdPlanesWaitingGreaterThanFiveHistoric;
      case EXCEEDED_CAPACITY_HISTORIC:               return new CmdPlanesOnLandExceededCapacityHistoric;
      case SENT_ANOTHER_AIRPORT_HISTORIC:            return new CmdPlanesSentAnotherAirportHistoric;
      case TAKE_OFF_REQUESTS_GREATER_THAN_FIVE:      return new CmdTakeOffRequestGreaterThanFiveHistoric;
      case CLS: gui->clearDisplay();                 return new CmdIdle();
      case EXIT: break;
      default: gui->showMessage("Invalid input \n"); return new CmdIdle();   
   }
   return nullptr;
}
