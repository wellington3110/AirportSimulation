#include "Simulator.h"
#include "Timer.h"
#include "Airport.h"


void Simulator::setUp()
{
   addObserversOfTimer();
}


void Simulator::addObserversOfTimer()
{
   Timer::getInstance()->add(Airport::getInstance());
}

void Simulator::generateEventsToWind()
{
   for (int eventTime = 0; eventTime < 4321;) {
      eventTime += generateNumberBetween(40, 16);
      windEventsTime.push(eventTime);
   }
}

void Simulator::generateEventsToPlane()
{
   for (int eventTime = 0; eventTime < 4321;) {
      eventTime += generateNumberBetween(4, 16);
      planeEventsTime.push(eventTime);
   }
}

int Simulator::generateNumberBetween(int min, int max)
{
   max = (max - min) + 1;
   return (rand() % max) + min;
}

