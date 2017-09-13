#include "AircraftManipulator.h"
#include "Random.h"
#include "Plane.h"
#include "Airport.h"
#include "AircraftLog.h"
#include <sstream>

AircraftManipulator* AircraftManipulator::instance= nullptr;

AircraftManipulator::~AircraftManipulator()
{
   for (iterAircraft iter= planes.begin(); iter != planes.end(); ++iter)
      delete *iter;
   delete AircraftLog::getInstance();
}

AircraftManipulator::AircraftManipulator() : planeNumber(0) 
{ 
   generateEventsToPlane();

   planeNames[1 ] = "Airbus A380";
   planeNames[2 ] = "Boeing 707";
   planeNames[3 ] = "Airbus A320";
   planeNames[4 ] = "Boeing 727";
   planeNames[5 ] = "Boeing 767";
   planeNames[6 ] = "Boeing 757";
   planeNames[7 ] = "Boeing 787";
   planeNames[8 ] = "Boeing 737";
   planeNames[9 ] = "Boeing 777";
   planeNames[10] = "Boeing 747";
}

AircraftManipulator* AircraftManipulator::getInstance()
{
   if (!instance)
      instance= new AircraftManipulator();
   return instance;
}

std::string AircraftManipulator::generatePlaneDescription()
{
   std::stringstream planeDescription;
   planeDescription << planeNames[Random::generateNumberBetween(1, 10)] + " de número de vôo " << planeNumber;
   return planeDescription.str();
}

void AircraftManipulator::generatePlane()
{
   int timeOnLand= Random::generateNumberBetween(20, 40);
   std::string planeDescription= generatePlaneDescription();
   Aircraft* newAircraft= new Plane(Airport::getInstance(), timeOnLand, AircraftLog::getInstance(), planeDescription);
   planes.push_back(newAircraft);
   planeNumber++;
}

void AircraftManipulator::generateEventsToPlane()
{
   for (int eventTime = 0; eventTime < 4320;) {
      eventTime+= Random::generateNumberBetween(4,16);
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







