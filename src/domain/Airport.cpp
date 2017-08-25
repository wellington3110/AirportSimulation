#include "Airport.h"
#include "Plane.h"

static TowerOfCommand* instance;

Airport::~Airport()
{
   instance= nullptr;
}

Airport::Airport(int _spaceOnLand): spaceOnLand(_spaceOnLand), planesOnLand(0)
{
   setUpRunWays();
}

void Airport::setUpRunWays()
{
   runWays.push_back(airportRunWay( RunWay(Wind::getInstance(), Wind::NORTH_SOUTH) ));
   runWays.push_back(airportRunWay( RunWay(Wind::getInstance(), Wind::LEST_WEST) ));
   runWays.push_back(airportRunWay( RunWay(Wind::getInstance(), Wind::NORTHEAST_SOUTHWEST) ));
}

//////////////////////////////////////////////////////////////////////////////
TowerOfCommand* Airport::getInstance()
{
   if(!instance)
      instance= getInstance(5);
   return instance;
}                             //
                                                                             
TowerOfCommand* Airport::getInstance(int _spaceOnLand)
{
   if(!instance)
      instance= new Airport(_spaceOnLand);
   return instance;
}                                                                                      
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
void Airport::updateRequests()
{
   updateFirstInQueue();
   updateTimeWaitingRequest();
}

void Airport::updateTimeWaitingRequest()
{
   for (iterRequests iter= requests.begin(); iter != requests.end(); ++iter) {
      addWaitingTime(*iter);
      do {
         if (landingIsInTimeOut(*iter)) {
            request* willDeleted = *iter;
            iter++;
            sendAircraftToAnotherAirport(willDeleted);
            addWaitingTime(*iter);
         }
      } while (*iter);
   }
}

void Airport::updateFirstInQueue()
{
   if(requests.size() > 0)
      if(releaseRunWay(requests.front()))
         requests.erase(requests.begin());
}

void Airport::update(const int& _actualTime)  
{
   actualTime= _actualTime;
   updateRequests();
}

//////////////////////////////////////////////////////////////////////////////



/////////////////////////////////Requisition Processes////////////////////////
void Airport::addRequestInQueue(request* request)
{
   bool hasThisRequestInQueue= false;
   for (iterRequests iter= requests.begin(); iter != requests.end(); ++iter)
      if( (*iter) == request )
         hasThisRequestInQueue= true;
   if(!hasThisRequestInQueue)
      requests.push_back(request);
}

bool Airport::releaseRunWay(request* planeRequest)
{
   airportRunWay* freeRunWay= getRunWayFree(planeRequest);
   if (freeRunWay){ 
      sendRequestToPlane(planeRequest);
      freeRunWay->plane= planeRequest->plane;
      freeRunWay->runWay.changeStatusToPlaneUsingRunWay();
      return true;
   }
   return false;
}

void Airport::receiveLandingRequest(Aircraft* plane)
{
   request* newRequest= createRequest(plane, LANDING);
   processesRequest(newRequest);
}

void Airport::receiveTakeOffRequest(Aircraft* plane)
{
   request* newRequest= createRequest(plane, TAKE_OFF);
   processesRequest(newRequest);
}

void Airport::sendRequestToPlane(request* planeRequest)
{
   if (planeRequest->actualStatus == LANDING)
      planeRequest->plane->receivePermissionToLand();
   else
      planeRequest->plane->receivePermissionToTakeOff();
}

void Airport::processesRequest(Airport::request* planeRequest)
{
   if(releaseRunWay(planeRequest))
      delete planeRequest;
   else
      addRequestInQueue(planeRequest);
}

void Airport::sendAircraftToAnotherAirport(request* planeRequest)
{
   requests.remove(planeRequest);
   //adicionar relatorio de avião enviado para outro aeroporto
}

Airport::airportRunWay* Airport::getRunWayFree(request* planeRequest)
{
   if(planeRequest->actualStatus == LANDING && !hasSpaceOnLand())
      return nullptr;

   for (iterRunWays iter= runWays.begin(); iter != runWays.end(); ++iter) {
      if(iter->runWay.isFree())
         return &*iter;
   }
   return nullptr;
}
//////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////
 Airport::airportRunWay* Airport::getRunWayBeingUsed(Aircraft* plane)
{
   for (iterRunWays iter= runWays.begin(); iter != runWays.end(); ++iter) {
      if (iter->plane == plane)
         return &*iter;
   }
   return nullptr;
}

void Airport::processesConfirmation(TypeConfirmation type, Aircraft* plane)
{
   airportRunWay* used= getRunWayBeingUsed(plane);
   if (used) {
      used->runWay.changeStatusToRunWayFree();
      used->plane= nullptr;
      if (type == LANDED)
         spaceOnLand++;
      else
         delete plane;
   } else
      ; //jogar uma expecetion
}
///////////////////////////////////////////////////////////////////////////////////////









