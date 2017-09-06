#pragma once

#ifndef INCLUDED_AIRCRAFT_H
#define INCLUDED_AIRCRAFT_H

#include <string>
class TowerOfCommand;

class Aircraft

{
public:
   virtual ~Aircraft() {}

   virtual void Aircraft::updateStatus() = 0;

   enum AircraftStatus {REQUESTING_LANDING, REQUESTING_TAKE_OFF, LANDING, TAKING_OFF, ON_LAND, TOOK_OFF, SENT_ANOTHER_AIRPORT};
   virtual AircraftStatus getActualStatus() = 0;
   virtual std::string getName() = 0;
   
   virtual bool receivePermissionToLand() = 0;
   virtual bool receivePermissionToTakeOff() = 0;
   virtual void receiveRequestToLandDenied() = 0;
};


#endif
