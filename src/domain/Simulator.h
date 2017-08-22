#pragma once
#include "TimerObserver.h"
#include <vector>

class Simulator : public TimerObserver
{
public:
   void run();   
private:
   void updateWind();
   void updatePlane();
   void update(int actualTime);
   
   void addObserversOfTimer();
   
   void generatePlane();
   void generateEventsToWind();
   void generateEventsToPlane();
   int generateNumberBetween(int min, int max);

private:
   int nextWindEventTime;
   int nextPlaneEventTime;

   std::vector<int> windEventsTime;
   std::vector<int> planeEventsTime;
   
};
