﻿#include "Plane.h"
#include "TowerOfCommand.h"
#include "Log.h"

Plane::Plane(TowerOfCommand* _airport, int _timeOnLand, Log* _log, std::string _name) :
   timeToRequestTakeOff(_timeOnLand), airport(_airport), aircraftLog(_log), name(_name)
{
   sendLandingRequest();
}

void Plane::updateStatus()
{
   switch(actualStatus)
   {
   case    LANDING: confirmLanding(); 
   break;
   case    TAKING_OFF: confirmTakeOff(); 
   break;
   case    ON_LAND: sendTakeOffRequest();
   break;
   default:;
   }
}


void Plane::confirmLanding()
{
   lessFourMinutesToHappen(timeToLand);
   if (isValidLanding()) {
      aircraftLog->generateLog(Log::CONFIRMING_LANDING, name);
      changeStatusTo(ON_LAND);
      airport->receiveConfirmationLanding(this); 
   }
}

void Plane::confirmTakeOff()
{
   lessFourMinutesToHappen(timeToTakeOff);
   if (isValidTakeOff()) {
      changeStatusTo(TOOK_OFF);
      aircraftLog->generateLog(Log::CONFIRMING_TAKEOFF, name);
      airport->receiveConfirmationTakeOff(this);
   }
}

void Plane::sendLandingRequest()
{
   aircraftLog->generateLog(Log::REQUESTING_LANDING, name);
   changeStatusTo(REQUESTING_LANDING);
   airport->receiveLandingRequest(this);
}

void Plane::sendTakeOffRequest()
{
   lessFourMinutesToHappen(timeToRequestTakeOff);
   if (isValidTimeToRequestTakeOff()) {
      aircraftLog->generateLog(Log::REQUESTING_TAKEOFF, name);
      changeStatusTo(REQUESTING_TAKE_OFF);
      airport->receiveTakeOffRequest(this);
   }
}

bool Plane::receivePermissionToLand()
{
   if (actualStatus == REQUESTING_LANDING) {
      changeStatusTo(LANDING);
      timeToLand= 12;
      aircraftLog->generateLog(Log::RECEIVE_PERMISSION_TOLAND, name);
      return true;
   }
   return false;   
}

bool Plane::receivePermissionToTakeOff()
{
   if (actualStatus == REQUESTING_TAKE_OFF) {
      changeStatusTo(TAKING_OFF);
      timeToTakeOff= 12;
      aircraftLog->generateLog(Log::RECEIVE_PERMISSION_TOTAKEOFF, name);
      return true;
   }
   return false;
}






