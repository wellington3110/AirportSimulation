#include "RunWay.h"

RunWay::RunWay(Wind* _wind, Wind::Direction _runWayDirection):
   wind(_wind), runWayDirection(_runWayDirection)
{
   actualStatus= FREE;
   verifyWind();
}


void RunWay::verifyWind()
{
   if(shouldBlockRunWay())
      actualStatus= BLOCKED_BY_WIND;
   else if(!hasPlaneUsingRunWay())
      actualStatus= FREE;
}

bool RunWay::shouldBlockRunWay() const
{
   return runWayDirection != wind->getDirection() && actualStatus == FREE;
}

bool RunWay::hasPlaneUsingRunWay() const
{
   return actualStatus == PLANE_USING_RUNWAY;
}

void RunWay::update()
{
   verifyWind();
}


bool RunWay::isFree() const
{
   return actualStatus == FREE;
}

bool RunWay::changeStatusToRunWayFree()
{
   if(hasPlaneUsingRunWay() || isFree()) {
      actualStatus= FREE;
      verifyWind();
      return true;
   }
   return false;
}

bool RunWay::changeStatusToPlaneUsingRunWay()
{
   if(isFree()) {
      actualStatus= PLANE_USING_RUNWAY;
      return true;
   }
   return false;   
}





