#include "RunWay.h"

RunWay::RunWay(Wind* _wind, Wind::Direction _runWayDirection):
   wind(_wind), runWayDirection(_runWayDirection)
{
   actualStatus= FREE;
   updateStatus();
}


void RunWay::updateStatus()
{
   if (blockRunWay())
      actualStatus= BLOCKED_BY_WIND;
   else if (!hasPlaneUsingRunWay())
      actualStatus= FREE;
}

void RunWay::changeStatusToRunWayFree()
{
   if (!isOppositeDirectionWind() || isFree()) {
      actualStatus= FREE;
   } else
      actualStatus= BLOCKED_BY_WIND;
}

void RunWay::changeStatusToPlaneUsingRunWay()
{
   if (isFree())
      actualStatus= PLANE_USING_RUNWAY;  
}





