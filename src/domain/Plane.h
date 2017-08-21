#pragma once

class Plane
{
public:
   enum planeStatus {REQUESTING_LANDING, REQUESTING_TAKEOFF, LANDING, TAKING_OFF, ON_LAND};


private:
   planeStatus actualStatus;
   
};
