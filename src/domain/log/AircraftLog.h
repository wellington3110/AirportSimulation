#pragma once
#ifndef INCLUDED_AIRCRAFTLOG_H
#define INCLUDED_AIRCRAFTLOG_H

#include "Log.h"

class AircraftLog : public Log
{
public:
   virtual ~AircraftLog(){}

   static Log* getInstance();

private:
   AircraftLog() {};
   AircraftLog(const AircraftLog&);

protected:
   void generateMessages();

};

#endif
