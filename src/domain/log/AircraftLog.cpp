#include "AircraftLog.h"

static Log* instance;

Log* AircraftLog::getInstance()
{
   if(!instance)
      instance= new AircraftLog;
   return instance;
}

void AircraftLog::generateMessages()
{
   messages[REQUESTING_LANDING                        ]= "Aircraft Log: Avião[x] solicitando pouso";
   messages[RECEIVE_PERMISSION_TOLAND                 ]= "Aircraft Log: Avião[x] recebeu permissão para pouso";
   messages[CONFIRMING_LANDING                        ]= "Aircraft Log: Avião[x] confirmando pouso";
   messages[REQUESTING_TAKEOFF                        ]= "Aircraft Log: Avião[x] solicitando decolagem";
   messages[RECEIVE_PERMISSION_TOTAKEOFF              ]= "Aircraft Log: Avião[x] recebeu permissão para decolagem";
   messages[CONFIRMING_TAKEOFF                        ]= "Aircraft Log: Avião[x] confirmando decolagem";
   messages[RECEIVE_REQUEST_TODRIVE_TO_ANOTHER_AIRPORT]= "Aircraft Log: Avião[x] recebeu o comando para se dirigir a outro aeroporto";
}                                                           
