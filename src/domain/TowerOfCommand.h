#pragma once
#ifndef INCLUDED_TOWEROFCOMMAND_H
#define INCLUDED_TOWEROFCOMMAND_H
#include "TimerObserver.h"

class Aircraft;

class TowerOfCommand : public TimerObserver
{
public:
   virtual ~TowerOfCommand() {}

   virtual void update(int& actualTime) = 0;
   
   virtual void sendAircraftToAnotherAirport() = 0;
   virtual void receiveLandingRequest(Aircraft* plane) = 0;
   virtual void receiveTakeOffRequest(Aircraft* plane) = 0; 
   virtual bool releaseRunwayForLanding(Aircraft* plane) = 0;
   virtual bool releaseRunwayForTakeOff(Aircraft* plane) = 0;
   virtual void receiveConfirmationLanding(Aircraft* plane) = 0;
   virtual void confirmConfirmationTakeOff(Aircraft* plane) = 0;
   
};


#endif
