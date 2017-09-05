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
   messages[RECEIVE_REQUEST_TOLAND           ]= "Recebe solicitação de pouso do avião [x]";
   messages[TORELEASE_RUNWAY_TOLAND          ]= "Libera pista para pouso ao avião [x]";
   messages[RECEIVE_CONFIRMING_OF_LANDING    ]= "Recebe confirmação de pouso do avião [x]";
   messages[RECEIVE_REQUEST_TOTAKEOFF        ]= "Recebe solicitação de decolagem do avião [x]";
   messages[TORELEASE_RUNWAY_TOTAKEOFF       ]= "Libera pista para decolagem ao avião [x]";
   messages[RECEIVE_CONFIRMING_OF_TAKEOFF    ]= "Recebe confirmação de decolagem do avião [x]";
   messages[REQUEST_INSERTED_IN_REQUESTSQUEUE]= "Solicitação do avião [x] inserida na fila de requisições";
   messages[AIRCRAFT_SENT_TO_ANOTHER_AIRPORT ]= "Encaminhado o avião [x] para outro aeroporto";

}                      
