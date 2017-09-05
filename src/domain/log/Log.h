#pragma once
#ifndef INCLUDED_LOG_H
#define INCLUDED_LOG_H

#include <map>

class Log
{
public:
   virtual ~Log(){}

   enum LogType 
   {
      RECEIVE_REQUEST_TOLAND= 1, TORELEASE_RUNWAY_TOLAND, RECEIVE_CONFIRMING_OF_LANDING,
      RECEIVE_REQUEST_TOTAKEOFF, TORELEASE_RUNWAY_TOTAKEOFF, RECEIVE_CONFIRMING_OF_TAKEOFF,
      REQUEST_INSERTED_IN_REQUESTSQUEUE, AIRCRAFT_SENT_TO_ANOTHER_AIRPORT,

      REQUESTING_LANDING= 11 , RECEIVE_PERMISSION_TOLAND, CONFIRMING_LANDING, 
      REQUESTING_TAKEOFF, RECEIVE_PERMISSION_TOTAKEOFF, CONFIRMING_TAKEOFF,
      RECEIVE_REQUEST_TODRIVE_TO_ANOTHER_AIRPORT,

      WIND_DIRECTION= 21
   };
   
   void generateLog(LogType type, std::string varValue);

protected:
   std::map<LogType, std::string> messages;
   virtual void generateMessages() = 0;

private:
   bool isValidType(LogType type);
   
};

#endif
