#include "AircraftManipulator.h"
#include "RandomNumberGenerator.h"
#include "Plane.h"
#include "Airport.h"
#include "AircraftLog.h"

static AircraftManipulator* instance;

AircraftManipulator::~AircraftManipulator()
{
   for (iterAircraft iter= planes.begin(); iter != planes.end(); ++iter)
      delete *iter;
}

AircraftManipulator* AircraftManipulator::getInstance()
{
   if (!instance)
      instance= new AircraftManipulator();
   return instance;
}


void AircraftManipulator::generatePlane()
{
   int timeOnLand= RandomNumberGenerator::generateNumberBetween(20, 40);
   Aircraft* newAircraft= new Plane(Airport::getInstance(), timeOnLand, AircraftLog::getInstance());
   planes.push_back(newAircraft);
}

void AircraftManipulator::generateEventsToPlane()
{
   for (int eventTime = 0; eventTime < 4320;) {
      eventTime+= RandomNumberGenerator::generateNumberBetween(4,16);
      planeEventsTime.push(eventTime);
   }
}


bool AircraftManipulator::aircraftTookOff(iterAircraft iter)
{
   return (*iter)->getActualStatus() == Aircraft::TOOK_OFF;
}

void AircraftManipulator::update(const int& actualTime)
{ 
   for (iterAircraft iter= planes.begin(); iter != planes.end();) {
      (*iter)->updateStatus();
      if (aircraftWasSentAnotherAirport(*iter) || aircraftTookOff(iter)) {
         delete *iter;
         iter= planes.erase(iter);
      } else
         ++iter;
   }

   if (isValidGenerateAircraft(actualTime)) {
      generatePlane();
      planeEventsTime.pop();     
   }

   
}






