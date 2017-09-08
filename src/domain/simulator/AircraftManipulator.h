#pragma once
#ifndef INCLUDED_PLANEMANIPULATOR_H
#define INCLUDED_PLANEMANIPULATOR_H

#include <map>
#include <queue>
#include "TimerObserver.h"
#include "Aircraft.h"

class AircraftManipulator: public TimerObserver
{
public:
   ~AircraftManipulator();

   static AircraftManipulator* getInstance();
   

   void generatePlane();
   void update(const int& actualTime);   
  
private:
   AircraftManipulator();
   AircraftManipulator(const AircraftManipulator&){}

   int planeNumber;

   std::queue<int> planeEventsTime;
   std::map<int, std::string> planeNames;

   std::vector<Aircraft*> planes;
   typedef std::vector<Aircraft*>::iterator iterAircraft;

   void generateEventsToPlane();
   std::string generatePlaneDescription();


   bool aircraftTookOff(iterAircraft iter);
   bool aircraftWasSentAnotherAirport(Aircraft* aircraft) { return aircraft->getActualStatus() == Aircraft::SENT_ANOTHER_AIRPORT; }
   bool isValidGenerateAircraft(const int& actualTime) { return planeEventsTime.front() <= actualTime && planeEventsTime.size() > 0; }
   
};

#endif
