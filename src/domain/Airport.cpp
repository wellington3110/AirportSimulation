#include "Airport.h"
#include "Plane.h"
#include <utility>

Airport::Airport(int _spaceOnLand): spaceOnLand(_spaceOnLand), planesOnLand(0), planesUsingRunWay(0)
{
   setUpRunWays();
}

//////////////////////////////////////////////////////////////////////////////

static TowerOfCommand* instance;

TowerOfCommand* Airport::getInstance()
{
   if(!instance)
      instance= getInstance(5);
   return instance;
}

TowerOfCommand* Airport::getInstance(int _spaceOnLand)
{
   if(!instance)
      instance= new Airport(_spaceOnLand);
   return instance;
}

//////////////////////////////////////////////////////////////////////////////



void Airport::setUpRunWays()
{
   runWays.push_back(AirportRunWay( RunWay(Wind::getInstance(), Wind::NORTH_SOUTH) ));
   runWays.push_back(AirportRunWay( RunWay(Wind::getInstance(), Wind::LEST_WEST) ));
   runWays.push_back(AirportRunWay( RunWay(Wind::getInstance(), Wind::NORTHEAST_SOUTHWEST) ));
}

void Airport::update(const int& actualTime)
{
      
}



//////////////////////////////////////////////////////////////////////////////
Airport::AirportRunWay* Airport::getRunWayFree()
{
   for (iterRunWay iter= runWays.begin(); iter != runWays.end(); ++iter) {
      if(iter->runWay.isFree())
         return &*iter;
   }
   return nullptr;
}

Airport::AirportRunWay* Airport::getRunWayBeingUsed(Aircraft* plane)
{
   for (iterRunWay iter= runWays.begin(); iter != runWays.end(); ++iter) {
      if(iter->plane == plane)
         return &*iter;
   }
   return nullptr;
}
/////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
void Airport::receiveLandingRequest(Aircraft* plane)
{
   if (hasSpaceOnLand() && hasRunWayFree())
      releaseRunWay(plane, LANDING);
   else
      requests.push_back(request(plane, LANDING));
}

void Airport::receiveTakeOffRequest(Aircraft* plane)
{
   if (hasSpaceOnLand() && hasRunWayFree())
      releaseRunWay(plane, TAKE_OFF);
   else
      requests.push_back(request(plane, TAKE_OFF));   
}

void Airport::releaseRunWay(Aircraft* plane, TypeRequest type)
{
   AirportRunWay* free= getRunWayFree();
   if (free != nullptr) {
      sendRequestToPlane(plane, type);
      free->plane= plane;
      free->runWay.changeStatusToPlaneUsingRunWay();
   } 
   else
      ;//jogar expception
}
//////////////////////////////////////////////////////////////////////////////



void Airport::sendRequestToPlane(Aircraft* plane, TypeRequest type)
{

   if(type == LANDING)
      plane->receivePermissionToLand();
   else
      plane->receivePermissionToTakeOff();
   planesUsingRunWay ++;
}


void Airport::processesConfirmation(TypeConfirmation type, Aircraft* plane)
{
   AirportRunWay* used= getRunWayBeingUsed(plane);
   used->runWay.changeStatusToRunWayFree();
   used->plane= nullptr;
   if(type == LANDED)
      spaceOnLand++;
   else
      ;/*delete plane;*/
}






