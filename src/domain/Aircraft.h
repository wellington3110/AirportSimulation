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

   virtual void update(int& actualTime) = 0;
   virtual AircraftStatus getActualStatus() = 0;
   

   virtual void receivePermissionToLand() = 0;
   virtual void receivePermissionToTakeOff() = 0;
   virtual void confirmLanding(TowerOfCommand* airport) = 0;
   virtual void confirmTakeOff(TowerOfCommand* airport) = 0;
   virtual void sendLandingRequest(TowerOfCommand* airport) = 0;
   virtual void sendTakeOffRequest(TowerOfCommand* airport) = 0;
};


#endif
