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
   void update(const int& actualTime);   
  
private:
   AircraftManipulator(){ generateEventsToPlane(); }
   AircraftManipulator(const AircraftManipulator&){}

   std::queue<int> planeEventsTime;

   std::vector<Aircraft*> planes;
   typedef std::vector<Aircraft*>::iterator iterAircraft;

   void generateEventsToPlane();
   bool aircraftTookOff(iterAircraft iter);

   bool aircraftWasSentAnotherAirport(Aircraft* aircraft) { return aircraft->getActualStatus() == Aircraft::SENT_ANOTHER_AIRPORT; }
   bool isValidGenerateAircraft(const int& actualTime) { return planeEventsTime.front() <= actualTime && planeEventsTime.size() > 0; }
   
};

#endif
