#include "AircraftManipulator.h"
#include "RandomNumberGenerator.h"
#include "Plane.h"
#include "Airport.h"
#include "Timer.h"

static AircraftManipulator* instance;

AircraftManipulator* AircraftManipulator::getInstance()
{
   if(!instance)
      instance= new AircraftManipulator();
   return instance;
}


void AircraftManipulator::generatePlane()
{
   int timeOnLand= RandomNumberGenerator::generateNumberBetween(20, 40);
   Aircraft* newAircraft= new Plane(Airport::getInstance(), timeOnLand);
   planes.push_back(newAircraft);
}

void AircraftManipulator::generateEventsToPlane()
{
   for (int eventTime = 0; eventTime < 4321;) {
      eventTime+= RandomNumberGenerator::generateNumberBetween(4,16);
      planeEventsTime.push(eventTime);
   }
}


void AircraftManipulator::update(const int& actualTime)
{ 
   for(iterAircraft iter= planes.begin(); iter != planes.end(); ++iter)
      (*iter)->updateStatus();
   if(planeEventsTime.size() > 0) {
      if (isValidGenerateAircraft(actualTime))
         generatePlane();
   }
   //delete aviões que fora enviados para outro aeroporto
}






