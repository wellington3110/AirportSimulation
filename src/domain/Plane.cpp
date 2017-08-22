#include "Plane.h"
#include "TowerOfCommand.h"

void Plane::receivePermissionToLand()
{
}

void Plane::receivePermissionToTakeOff()
{
}

void Plane::sendLandingRequest(TowerOfCommand* airport)
{
   actualStatus= AircraftStatus::REQUESTING_LANDING;
   airport->receiveLandingRequest(this);
}

void Plane::sendTakeOffRequest(TowerOfCommand* airport)
{
   actualStatus= AircraftStatus::REQUESTING_TAKE_OFF;
   airport->receiveTakeOffRequest(this);
}




