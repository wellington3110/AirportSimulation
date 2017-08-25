#pragma once
#ifndef INCLUDED_PLANEMANIPULATOR_H
#define INCLUDED_PLANEMANIPULATOR_H

#include <queue>
#include "TimerObserver.h"
#include "Aircraft.h"

class AircraftManipulator: public TimerObserver
{
public:

   static AircraftManipulator* getInstance();

   void generatePlane();
   void generateEventsToPlane();

   void update(const int& actualTime);


   bool isValidGenerateAircraft(const int& actualTime) {return planeEventsTime.front() <= actualTime;}
   bool aircraftWasSentAnotherAirport(Aircraft* aircraft) {return aircraft->getActualStatus() == Aircraft::SENT_ANOTHER_AIRPORT;}
  
private:
   AircraftManipulator(){generateEventsToPlane();}
   AircraftManipulator(const AircraftManipulator&){}

   std::queue<int> planeEventsTime;
   std::vector<Aircraft*> planes;
   typedef std::vector<Aircraft*>::iterator iterAircraft;

   typedef std::vector<Aircraft*>::iterator iterPlanes;
   std::vector<iterPlanes> recycleBin;

   
};

#endif
