#pragma once
#ifndef INCLUDED_TIMER_H
#define INCLUDED_TIMER_H

#include "Observable.h"
#include <vector>

class Timer : public Observable
{
public:
   void start();

   static Timer* getInstance();

   void notifyAll();
   void add(TimerObserver* observer){ observers.push_back(observer); }
   
private:
   Timer(Timer& c);
   Timer() : actualTime(0) {}

   int actualTime;
   std::vector<TimerObserver*> observers;
   typedef std::vector<TimerObserver*>::iterator iter;
};

#endif
