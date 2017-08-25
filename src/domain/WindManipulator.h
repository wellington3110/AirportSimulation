#pragma once
#ifndef INCLUDED_WINDMANIPULATOR_H
#define INCLUDED_WINDMANIPULATOR_H

#include "TimerObserver.h"
#include <queue>

class WindManipulator : public TimerObserver
{
public:
   static WindManipulator* getInstance();

   void generateEventsToWind();
   bool isValidUpdateStatusWind(const int& actualTime){return windEventsTime.front() <= actualTime;}
   void update(const int& actualTime);

private:
   WindManipulator(){generateEventsToWind();}
   WindManipulator(const WindManipulator&){}

   std::queue<int> windEventsTime;
};

#endif

