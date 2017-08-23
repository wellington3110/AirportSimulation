#pragma once
#ifndef INCLUDED_AIRPORT_H
#define INCLUDED_AIRPORT_H

#include "TowerOfCommand.h"
#include <list>
#include "RunWay.h"

class Airport : public TowerOfCommand
{
public:
   static TowerOfCommand* getInstance();
   
   static TowerOfCommand* getInstance(int _spaceOnLand);

   enum TypeRequest {TAKE_OFF, LANDING};
   enum TypeConfirmation {TOOK_OFF, LANDED};

   virtual void update(const int& actualTime);

   virtual void receiveLandingRequest(Aircraft* plane);
   virtual void receiveTakeOffRequest(Aircraft* plane);
   virtual void receiveConfirmationLanding(Aircraft* plane) {processesConfirmation(LANDED, plane);}
   virtual void receiveConfirmationTakeOff(Aircraft* plane) {processesConfirmation(TOOK_OFF, plane);}

private:
   Airport(int _spaceOnLand);

   int spaceOnLand;
   int planesOnLand;
   int planesUsingRunWay;

   struct request
   {
      Aircraft* plane;
      int waitingTime;
      TypeRequest type;
      request(Aircraft* _plane, TypeRequest _type) : plane(_plane), waitingTime(0), type(_type){}
   };

   struct AirportRunWay
   {
      RunWay runWay;
      Aircraft* plane;
      AirportRunWay(RunWay _runWay) : runWay(_runWay) {};
   };

   std::list<request>requests;

   typedef std::list<AirportRunWay>::iterator iterRunWay;
   std::list<AirportRunWay>runWays;

   void setUpRunWays();
   bool hasRunWayFree(){return true;}
   bool hasSpaceOnLand(){return true;}
   AirportRunWay* getRunWayFree();
   AirportRunWay* getRunWayBeingUsed(Aircraft* plane);
   void processesConfirmation(TypeConfirmation type, Aircraft* plane);

   void sendAircraftToAnotherAirport() {}
   void releaseRunWay(Aircraft* plane, TypeRequest type);
   void sendRequestToPlane(Aircraft* plane, TypeRequest type);
};

#endif