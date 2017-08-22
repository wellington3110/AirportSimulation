#include "Simulator.h"


void Simulator::generateEventsToWind()
{
   for (int eventTime = 0; eventTime < 4321;) {
      eventTime += generateNumberBetween(40, 16);
      windEventsTime.push_back(eventTime);
   }
}

void Simulator::generateEventsToPlane()
{
   for (int eventTime = 0; eventTime < 4321;) {
      eventTime += generateNumberBetween(4, 16);
      planeEventsTime.push_back(eventTime);
   }
}



int Simulator::generateNumberBetween(int min, int max)
{
   max = (max - min) + 1;
   return (rand() % max) + min;
}

