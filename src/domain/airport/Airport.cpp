#include "Airport.h"
#include "Aircraft.h"
#include "Data.h"
#include "Log.h"

static TowerOfCommand* instance;


Airport::~Airport()
{
   for (iterRequests request= requests.begin(); request != requests.end(); ++request)
      delete *request;
   delete towerCommandLog;
}

Airport::Airport(int _spaceOnLand, Log* _towerCommandLog): DataVendorToReport(), spaceOnLand(_spaceOnLand), planesOnLand(0), takeOffPending(0), planesLanding(0),
towerCommandLog(_towerCommandLog)
{

   setUpRunWays();
}

void Airport::setUpRunWays()
{
   runWays.push_back(AirportRunWay( RunWay(Wind::getInstance(), Wind::NORTH_SOUTH) ));
   runWays.push_back(AirportRunWay( RunWay(Wind::getInstance(), Wind::LEST_WEST) ));
   runWays.push_back(AirportRunWay( RunWay(Wind::getInstance(), Wind::NORTHEAST_SOUTHWEST) ));
}

//////////////////////////////////////////////////////////////////////////////
TowerOfCommand* Airport::getInstance()
{
   if (!instance)
      instance= getInstance(5, nullptr);
   return instance;
}                             //
                                                                             
TowerOfCommand* Airport::getInstance(int _spaceOnLand, Log* _towerCommandLog)
{
   if (!instance)
      instance= new Airport(_spaceOnLand, _towerCommandLog);
   return instance;
}                                                                                      
//////////////////////////////////////////////////////////////////////////////



//--------------------------------Process of update---------------------------/
//////////////////////////////////////////////////////////////////////////////

void Airport::update(const int& _actualTime)  
{
   actualTime= _actualTime;
   updateRunWays();
   updateRequests();
   updateCriticalReports();

}

void Airport::updateRunWays()
{
   for (iterRunWays iter= runWays.begin(); iter != runWays.end(); ++iter)
      iter->runWay.updateStatus();
}

//////////////////////////////////////////////////////////////////////////////

void Airport::updateRequests()
{ 
   updateFirstInQueue();
   updateWaitingTimeRequest();
}

void Airport::updateFirstInQueue()
{
   if ( capacityExceeded() && !isTakeOffFirstInQueue()) 
      putTakeOffRequestAtFirstInQueue();

   if (requests.size() > 0)
      if (releaseRunWay(requests.front())) {
         delete requests.front();
         requests.pop_front();
      }
}

void Airport::updateWaitingTimeRequest()
{
   for (iterRequests request= requests.begin(); request != requests.end();) {
      addWaitingTime(*request);
      if (landingIsInTimeOut(*request)) {
         sendAircraftToAnotherAirport(*request);
         delete *request;
         request= requests.erase(request);
      } else
         ++request;
   }
}

void Airport::putTakeOffRequestAtFirstInQueue()
{
   for (iterRequests request= requests.begin(); request != requests.end(); request++) {
      if ( (*request)->actualStatus == TAKE_OFF ) {
         Request* firstInQueue= new Request(*request);
         delete *request;
         requests.erase(request);
         requests.push_front(firstInQueue);
         break;
      }
   }
}

//////////////////////////////////////////////////////////////////////////////

void Airport::updateCriticalReports()
{ 
   updatePlanesWaitingGreaterThanFiveReport();   
   updateCapacityExceededReport();
   updatePlanesRequestingTakeOffGreaterThanFiveReport();
   updatePlanesWaitingAmountReport();
}

void Airport::updateCapacityExceededReport()
{
   if( capacityExceeded() )
      sendDateToReport(Data::createData(actualTime, Data::PLANES_ON_LAND_EXCEEDED_CAPACITY));
}

void Airport::updatePlanesWaitingAmountReport()
{
   if (requests.size() > 0)
      sendDateToReport(Data::createData(requests.back()->waitingTime, requests.size(), Data::PLANES_WAITING));
}

void Airport::updatePlanesWaitingGreaterThanFiveReport()
{
   if (requests.size() > 5) 
      sendDateToReport(Data::createData(actualTime, Data::WAITING_GREATER_THAN_5));
}

void Airport::updatePlanesRequestingTakeOffGreaterThanFiveReport()
{
   if (takeOffPending > 5)
      sendDateToReport(Data::createData(actualTime, Data::REQUESTING_TAKE_OFF_GREATER_THAN_5));
}

//////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------/



/////////////////////////////////Requisition Processes////////////////////////
bool Airport::releaseRunWay(Request* planeRequest)
{
   AirportRunWay* freeRunWay= getRunWayFree(planeRequest);
   if (freeRunWay){ 
      sendPermissionToPlane(planeRequest);
      freeRunWay->plane= planeRequest->plane;
      freeRunWay->runWay.changeStatusToPlaneUsingRunWay();
      return true;
   }
   return false;
}

void Airport::receiveLandingRequest(Aircraft* plane)
{
   towerCommandLog->generateLog(Log::RECEIVE_REQUEST_TOLAND, plane->getName());
   Request* newRequest= new Request(plane, LANDING);
   processesRequest(newRequest);
}

void Airport::receiveTakeOffRequest(Aircraft* plane)
{
   towerCommandLog->generateLog(Log::RECEIVE_REQUEST_TOTAKEOFF, plane->getName());
   Request* newRequest= new Request(plane, TAKE_OFF);
   takeOffPending ++;
   processesRequest(newRequest); 
}

void Airport::processesRequest(Request* planeRequest)
{
   if (requests.size() == 0 && releaseRunWay (planeRequest))
      delete planeRequest;
   else {
      requests.push_back(planeRequest);
      towerCommandLog->generateLog(Log::REQUEST_INSERTED_IN_REQUESTSQUEUE, planeRequest->plane->getName());
   }
}

void Airport::sendPermissionToPlane(Request* planeRequest)
{
   if (planeRequest->actualStatus == LANDING) {
      towerCommandLog->generateLog(Log::TORELEASE_RUNWAY_TOLAND, planeRequest->plane->getName());
      planeRequest->plane->receivePermissionToLand();
      planesLanding++;
      planesOnLand++;
   } else {
      towerCommandLog->generateLog(Log::TORELEASE_RUNWAY_TOTAKEOFF, planeRequest->plane->getName());
      planeRequest->plane->receivePermissionToTakeOff();
      takeOffPending --;
      planesOnLand --;
   }
   sendDateToReport(Data::createData(planesOnLand, Data::PLANES_ON_LAND));
}

void Airport::sendAircraftToAnotherAirport(Request* planeRequest)
{
   planeRequest->plane->receiveRequestToLandDenied();
   sendDateToReport(Data::createData(actualTime, Data::PLANES_SENT_ANOTHER_AIRPORT));
   towerCommandLog->generateLog(Log::AIRCRAFT_SENT_TO_ANOTHER_AIRPORT, planeRequest->plane->getName());
}

Airport::AirportRunWay* Airport::getRunWayFree(Request* planeRequest)
{
   if (planeRequest->actualStatus == LANDING && !hasSpaceOnLand())
      return nullptr;

   for (iterRunWays iter= runWays.begin(); iter != runWays.end(); ++iter) {
      if (iter->runWay.isFree())
         return &*iter;
   }
   return nullptr;
}
//////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////
void Airport::receiveConfirmationLanding(Aircraft* plane)
{
   processesConfirmation(plane);
   towerCommandLog->generateLog(Log::RECEIVE_CONFIRMATION_OF_LANDING, plane->getName());
   sendDateToReport(Data::createData(planesLanding, Data::LANDED));
} 

void Airport::receiveConfirmationTakeOff(Aircraft* plane)
{
   processesConfirmation(plane);
   towerCommandLog->generateLog(Log::RECEIVE_CONFIRMATION_OF_TAKEOFF, plane->getName());
}

Airport::AirportRunWay* Airport::getRunWayBeingUsed(Aircraft* plane)
{
   for (iterRunWays iter= runWays.begin(); iter != runWays.end(); ++iter) {
      if (iter->plane == plane)
         return &*iter;
   }
   return nullptr;
}

void Airport::processesConfirmation(Aircraft* plane)
{
   AirportRunWay* used= getRunWayBeingUsed(plane);
   if (used) {
      used->runWay.changeStatusToRunWayFree();
      used->plane= nullptr;      
   } else
      ; //jogar uma expception
}
///////////////////////////////////////////////////////////////////////////////////////









