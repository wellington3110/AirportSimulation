#pragma once

#ifndef INCLUDED_AIRCRAFT_H
#define INCLUDED_AIRCRAFT_H
#include "TimerObserver.h"

class TowerOfCommand;

class Aircraft : public TimerObserver

{
public:
   virtual ~Aircraft() {}
   enum AircraftStatus {REQUESTING_LANDING, REQUESTING_TAKE_OFF, LANDING, TAKING_OFF, ON_LAND, TOOK_OFF};

   virtual void update(const int& actualTime) = 0;
   virtual AircraftStatus getActualStatus() = 0;
   
   virtual bool receivePermissionToLand() = 0;
   virtual bool receivePermissionToTakeOff() = 0;
};


#endif
