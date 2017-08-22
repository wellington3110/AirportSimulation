#pragma once
#ifndef INCLUDED_RUNWAY_H 
#define INCLUDED_RUNWAY_H

#include "Wind.h"
#include "TimerObserver.h"

class RunWay : public TimerObserver 
{
public:
   RunWay(Wind* _wind, Wind::Direction _runWayDirection);
  
   enum RunWayStatus {FREE, PLANE_USING_RUNWAY, BLOCKED_BY_WIND};

   void update(int& actualTime) {};

   void verifyWind();
   bool isFree() const;
   bool changeStatusToRunWayFree();
   bool changeStatusToPlaneUsingRunWay();

   RunWayStatus getActualStatus() const { return actualStatus; }
   
private:
   Wind* wind;
   RunWayStatus actualStatus;
   Wind::Direction runWayDirection;

   bool shouldBlockRunWay() const;
   bool hasPlaneUsingRunWay() const;

};

#endif

