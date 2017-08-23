#pragma once
#ifndef INCLUDED_AIRCRAFTFAKE 
#define INCLUDED_AIRCRAFTFAKE
#include "Aircraft.h"

class AircraftFake : public Aircraft
{
public:

   AircraftFake() : updateCall(false) {}

   bool updateCall;

   virtual AircraftStatus getActualStatus()
   {
      return actualStatus;
   }

   virtual void update(const int& actualTime)
   {
      updateCall= true;  
   }

   bool receivePermissionToLand()
   {
      actualStatus= LANDING;
      return true;
   }

   bool receivePermissionToTakeOff()
   {
      actualStatus= TAKING_OFF;
      return true;
   }



private:
   AircraftStatus actualStatus;
   
};





#endif
