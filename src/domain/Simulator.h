#pragma once
#ifndef INCLUDED_SIMULATOR_H
#define INCLUDED_SIMULATOR_H

#include "TimerObserver.h"
#include <queue>

class Simulator : public TimerObserver
{
public:
   void setUp();   
private:
   void updateWind();
   void updatePlane();
   void update(const int& actualTime);
   
   void addObserversOfTimer();
   
   void generatePlane();
   void generateEventsToWind();
   void generateEventsToPlane();
   int generateNumberBetween(int min, int max);

private:
   int nextWindEventTime;
   int nextPlaneEventTime;

   std::queue<int> windEventsTime;
   std::queue<int> planeEventsTime;
   
};

#endif
