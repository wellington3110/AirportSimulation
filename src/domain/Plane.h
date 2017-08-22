#pragma once
#ifndef INCLUDED_PLANE_H
#define INCLUDED_PLANE_H
#include "Aircraft.h"

class TowerOfCommand;

class Plane : public Aircraft
{
public:

   void update(int& actualTime);

   void receivePermissionToLand();
   void receivePermissionToTakeOff();
   void confirmLanding(TowerOfCommand* airport);
   void confirmTakeOff(TowerOfCommand* airport);
   void sendLandingRequest(TowerOfCommand* airport);
   void sendTakeOffRequest(TowerOfCommand* airport);
   
   AircraftStatus getActualStatus() { return actualStatus; }

private:
   AircraftStatus actualStatus;
};

#endif
