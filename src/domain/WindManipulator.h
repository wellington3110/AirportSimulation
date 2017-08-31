#pragma once
#ifndef INCLUDED_WINDMANIPULATOR_H
#define INCLUDED_WINDMANIPULATOR_H

#include "TimerObserver.h"
#include <queue>

class WindManipulator : public TimerObserver
{
public:
   ~WindManipulator();

   static WindManipulator* getInstance();
   
   void update(const int& actualTime);

private:
   WindManipulator(){ generateEventsToWind();}
   WindManipulator(const WindManipulator&){}

   std::queue<int> windEventsTime;

   void generateEventsToWind();

   bool isValidUpdateStatusWind(const int& actualTime) { return windEventsTime.front() <= actualTime && windEventsTime.size() > 0; }

};

#endif

