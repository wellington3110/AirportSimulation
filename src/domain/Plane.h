#pragma once
#ifndef INCLUDED_PLANE_H
#define INCLUDED_PLANE_H

#include "Aircraft.h"

class TowerOfCommand;

class Plane : public Aircraft
{
public:
   Plane(TowerOfCommand* _airport, int _timeOnLand);
 
   void updateStatus();

   virtual bool receivePermissionToLand();
   virtual bool receivePermissionToTakeOff();

   virtual void receiveRequestToLandDenied() {changeStatusTo(SENT_ANOTHER_AIRPORT);}

   AircraftStatus getActualStatus() { return actualStatus; }

private:
   int timeToLand;
   int timeToTakeOff;
   int timeToRequestTakeOff;

   TowerOfCommand* airport;
   AircraftStatus actualStatus;

   void confirmLanding();
   void confirmTakeOff();
   void sendLandingRequest();
   void sendTakeOffRequest();
   void changeStatusTo(AircraftStatus newStatus) {actualStatus= newStatus;}

   void lessFourMinutesToHappen(int& timeEvent) {timeEvent -= 4;}

   bool isValidLanding() {return timeToLand == 0;}
   bool isValidTakeOff() {return timeToTakeOff == 0;}
   bool isValidTimeToRequestTakeOff(){ return timeToRequestTakeOff <= 0;}

};

#endif
