#pragma once
#ifndef INCLUDED_AIRPORT_H
#define INCLUDED_AIRPORT_H

#include "TowerOfCommand.h"
#include <list>
#include "RunWay.h"

class Airport : public TowerOfCommand
{
public:
   ~Airport();

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

   struct request
   {
      Aircraft* plane;
      int waitingTime;
      TypeRequest actualStatus;
      request(Aircraft* _plane, TypeRequest _type) : plane(_plane), waitingTime(0), actualStatus(_type){}
   };

   struct airportRunWay
   {
      RunWay runWay;
      Aircraft* plane;
      airportRunWay(RunWay _runWay) : runWay(_runWay), plane(nullptr) {};
   };

   int actualTime;
   int spaceOnLand;
   int planesOnLand; 

   typedef std::list<request*>::iterator iterRequests;
   std::list<request*>requests;

   typedef std::list<airportRunWay>::iterator iterRunWays;
   std::list<airportRunWay>runWays;

   airportRunWay* getRunWayFree(request* planeRequest);
   airportRunWay* getRunWayBeingUsed(Aircraft* plane);

   request* createRequest(Aircraft* plane, TypeRequest type) {return new request(plane, type);}

   bool releaseRunWay(request* planeRequest);
   bool hasSpaceOnLand() {return spaceOnLand > planesOnLand;}
   bool landingIsInTimeOut(request* planeRequest){return (planeRequest->waitingTime == 32 && planeRequest->actualStatus == LANDING);}
   
   void setUpRunWays();
   void updateRequests();
   void updateFirstInQueue();
   void updateTimeWaitingRequest();
   void addRequestInQueue(request* request);
   void processesRequest(request* newRequest);
   void sendRequestToPlane(request* planeRequest);
   void sendAircraftToAnotherAirport(request* planeRequest);
   void processesConfirmation(TypeConfirmation type, Aircraft* plane);
   void addWaitingTime(request* planeRequest) { planeRequest->waitingTime += 4; }

};

#endif