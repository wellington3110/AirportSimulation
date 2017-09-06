#include "TowerOfCommandLog.h"

static Log* instance;

Log* TowerOfCommandLog::getInstance()
{
   if(!instance)
      instance= new TowerOfCommandLog;
   return instance;
}


void TowerOfCommandLog::generateMessages()
{
   messages[RECEIVE_REQUEST_TOLAND           ]= "TowerOfCommand Log: Recebe solicitação de pouso do avião [x]";
   messages[TORELEASE_RUNWAY_TOLAND          ]= "TowerOfCommand Log: Libera pista para pouso ao avião [x]";
   messages[RECEIVE_CONFIRMATION_OF_LANDING  ]= "TowerOfCommand Log: Recebe confirmação de pouso do avião [x]";
   messages[RECEIVE_REQUEST_TOTAKEOFF        ]= "TowerOfCommand Log: Recebe solicitação de decolagem do avião [x]";
   messages[TORELEASE_RUNWAY_TOTAKEOFF       ]= "TowerOfCommand Log: Libera pista para decolagem ao avião [x]";
   messages[RECEIVE_CONFIRMATION_OF_TAKEOFF  ]= "TowerOfCommand Log: Recebe confirmação de decolagem do avião [x]";
   messages[REQUEST_INSERTED_IN_REQUESTSQUEUE]= "TowerOfCommand Log: Solicitação do avião [x] inserida na fila de requisições";
   messages[AIRCRAFT_SENT_TO_ANOTHER_AIRPORT ]= "TowerOfCommand Log: Encaminhado o avião [x] para outro aeroporto";

}                      
