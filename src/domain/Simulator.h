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
   void generateEventsToWindCreation();
   void generateEventsToPlaneCreation();

private:
   std::vector<int> eventsTimeToPlaneCreation;
};
