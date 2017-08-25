#pragma once
#ifndef INCLUDED_RUNWAY_H 
#define INCLUDED_RUNWAY_H

#include "Wind.h"

class RunWay
{
public:
   RunWay(Wind* _wind, Wind::Direction _runWayDirection);
  
   enum RunWayStatus {FREE, PLANE_USING_RUNWAY, BLOCKED_BY_WIND};

   void updateStatus();

   void changeStatusToRunWayFree();
   void changeStatusToPlaneUsingRunWay();
   bool isFree(){return actualStatus == FREE;}

   RunWayStatus getActualStatus() const { return actualStatus; }
   
private:
   Wind* wind;
   RunWayStatus actualStatus;
   Wind::Direction runWayDirection;

   bool hasPlaneUsingRunWay() {return actualStatus == PLANE_USING_RUNWAY;}
   bool isOppositeDirectionWind(){return runWayDirection != wind->getDirection();}
   bool blockRunWay() {return isOppositeDirectionWind() && !hasPlaneUsingRunWay();}

};

#endif

