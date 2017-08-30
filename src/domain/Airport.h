#pragma once
#ifndef INCLUDED_AIRPORT_H
#define INCLUDED_AIRPORT_H

#include "TowerOfCommand.h"
#include <list>
#include "RunWay.h"
#include "DataVendorToReport.h"

class Airport : public TowerOfCommand, public DataVendorToReport
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
   virtual void receiveConfirmationLanding(Aircraft* plane);
   virtual void receiveConfirmationTakeOff(Aircraft* plane) {processesConfirmation(TOOK_OFF, plane);}
   

private:
   Airport(int _spaceOnLand);
   Airport(const Airport& c);

   struct Request
   {
      Aircraft* plane;
      int waitingTime;
      TypeRequest actualStatus;
      Request(Aircraft* _plane, TypeRequest _type) : plane(_plane), waitingTime(0), actualStatus(_type){}
      Request(const Request* _request) : plane(_request->plane), waitingTime(_request->waitingTime), actualStatus(_request->actualStatus){}
   };

   struct AirportRunWay
   {
      RunWay runWay;
      Aircraft* plane;
      AirportRunWay(RunWay _runWay) : runWay(_runWay), plane(nullptr) {};
   };

   int actualTime;
   int spaceOnLand;
   int planesOnLand;
   int planesLanding;
   int takeOffPending;
   
   
   std::list<Request*>requests;
   typedef std::list<Request*>::iterator iterRequests;

   std::list<AirportRunWay>runWays;
   typedef std::list<AirportRunWay>::iterator iterRunWays;

   AirportRunWay* getRunWayBeingUsed(Aircraft* plane);
   AirportRunWay* getRunWayFree(Request* planeRequest);

   bool releaseRunWay(Request* planeRequest);
   bool hasSpaceOnLand() {return spaceOnLand > planesOnLand;}
   bool capacityExceeded() {return planesOnLand > (spaceOnLand * 70) / 100 ;}
   bool isTakeOffFirstInQueue() {return requests.size() > 0 ? requests.front()->actualStatus == TAKE_OFF : false;}
   bool landingIsInTimeOut(Request* planeRequest){return (planeRequest->waitingTime >= 32 && planeRequest->actualStatus == LANDING);}
   
   void setUpRunWays();
   void updateRunWays();
   void updateRequests();
   void updateFirstInQueue();
   void updateCriticalReports();
   void updateWaitingTimeRequest();
   void updateCapacityExceededReport();
   void updatePlanesWaitingAmountReport();
   void putTakeOffRequestAtFirstInQueue();
   void processesRequest(Request* newRequest);
   void updatePlanesWaitingGreaterThanFiveReport();
   void sendPermissionToPlane(Request* planeRequest);
   void sendAircraftToAnotherAirport(Request* planeRequest);
   void updatePlanesRequestingTakeOffGreaterThanFiveReport();
   void processesConfirmation(TypeConfirmation type, Aircraft* plane);
   void addWaitingTime(Request* planeRequest) { planeRequest->waitingTime += 4; }

};

#endif