#include "Plane.h"
#include "TowerOfCommand.h"

Plane::Plane(TowerOfCommand* _airport, int _timeOnLand): airport(_airport), timeToRequestTakeOff(_timeOnLand)
{
   sendLandingRequest();
}

void Plane::updateStatus()
{
   switch(actualStatus)
   {
   case    LANDING: confirmLanding(); 
   break;
   case TAKING_OFF: confirmTakeOff(); 
   break;
   case    ON_LAND: sendTakeOffRequest();
   break;
   }
}


void Plane::confirmLanding()
{
   lessFourMinutesToHappen(timeToLand);
   if (isValidLanding()) {
      changeStatusTo(ON_LAND);
      airport->receiveConfirmationLanding(this);   
   }
}

void Plane::confirmTakeOff()
{
   lessFourMinutesToHappen(timeToTakeOff);
   if (isValidTakeOff()) {
      changeStatusTo(TOOK_OFF);
      airport->receiveConfirmationTakeOff(this);   
   }
}

void Plane::sendLandingRequest()
{
   changeStatusTo(REQUESTING_LANDING);
   airport->receiveLandingRequest(this);
}

void Plane::sendTakeOffRequest()
{
   lessFourMinutesToHappen(timeToRequestTakeOff);
   if (isValidTimeToRequestTakeOff()) {
      changeStatusTo(REQUESTING_TAKE_OFF);
      airport->receiveTakeOffRequest(this);   
   }
}

bool Plane::receivePermissionToLand()
{
   if (actualStatus == REQUESTING_LANDING) {
      changeStatusTo(LANDING);
      timeToLand= 12;
      return true;
   }
   return false;   
}

bool Plane::receivePermissionToTakeOff()
{
   if (actualStatus == REQUESTING_TAKE_OFF) {
      changeStatusTo(TAKING_OFF);
      timeToTakeOff= 12;
      return true;
   }
   return false;
}






