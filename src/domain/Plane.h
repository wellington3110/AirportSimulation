#pragma once
#ifndef INCLUDED_PLANE_H
#define INCLUDED_PLANE_H

class Airport;

class Plane
{
public:
   enum planeStatus {REQUESTING_LANDING, REQUESTING_TAKEOFF, LANDING, TAKING_OFF, ON_LAND};

private:
   Airport* airport;
   planeStatus actualStatus;
};

#endif
