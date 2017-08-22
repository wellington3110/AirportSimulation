#pragma once
#ifndef INCLUDED_AIRCRAFTMOCK 
#define INCLUDED_AIRCRAFTMOCK
#include "Aircraft.h"

class AircraftMock : public Aircraft
{
public:

   AircraftMock() {}

   virtual AircraftStatus getActualStatus()
   {
      return actualStatus;
   }

   virtual void update(int& actualTime) {}

   void receivePermissionToLand();
   void receivePermissionToTakeOff();
   void confirmLanding(TowerOfCommand* airport);
   void confirmTakeOff(TowerOfCommand* airport);
   void sendLandingRequest(TowerOfCommand* airport);
   void sendTakeOffRequest(TowerOfCommand* airport);

   bool expectationsAboutLanding();
   bool expectationsAboutTakeOff();

private:
   AircraftStatus actualStatus;
};

inline bool AircraftMock::expectationsAboutLanding()
{                   
   if(actualStatus == ON_LAND)
      return true;
   return false;
}                   
                    
inline bool AircraftMock::expectationsAboutTakeOff()
{
   if(actualStatus == TOOK_OFF)
      return true;
   return false;
}

inline void AircraftMock::receivePermissionToLand()
{
   if(actualStatus == REQUESTING_LANDING)
      actualStatus= LANDING;    
}

inline void AircraftMock::receivePermissionToTakeOff()
{
   if(actualStatus == REQUESTING_TAKE_OFF)
      actualStatus= TAKING_OFF;

}

inline void AircraftMock::confirmLanding(TowerOfCommand* airport)
{
   if(actualStatus == LANDING)
      actualStatus= ON_LAND;

}

inline void AircraftMock::confirmTakeOff(TowerOfCommand* airport)
{
   if(actualStatus == TAKING_OFF)
      actualStatus= TOOK_OFF;
}

inline void AircraftMock::sendLandingRequest(TowerOfCommand* airport)
{  actualStatus= REQUESTING_LANDING;
}

inline void AircraftMock::sendTakeOffRequest(TowerOfCommand* airport)
{
   actualStatus= REQUESTING_TAKE_OFF;
}



#endif
