#pragma once
#ifndef INCLUDED_AIRPORT_H
#define INCLUDED_AIRPORT_H
#include "TowerOfCommand.h"

class Airport : public TowerOfCommand
{
public:
   static TowerOfCommand* getInstance();

   virtual void update(int& actualTime) {};
   
   void sendAircraftToAnotherAirport() {}
   void receiveLandingRequest(Aircraft* plane) {}
   void receiveTakeOffRequest(Aircraft* plane) {} 
   bool releaseRunwayForLanding(Aircraft* plane) {return false;}
   bool releaseRunwayForTakeOff(Aircraft* plane) {return false;}
   void receiveConfirmationLanding(Aircraft* plane) {}
   void confirmConfirmationTakeOff(Aircraft* plane) {}

private:
   Airport() {};
};

#endif