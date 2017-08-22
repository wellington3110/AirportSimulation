﻿#include "Timer.h"
#include "TimerObserver.h"
#include<ctime>

static Timer* instance;

void Timer::start()
{
   int sec= 0;
   do {
      actualTime= clock()/CLOCKS_PER_SEC;
      if(actualTime > sec) {
         notifyAll();
         sec ++;
      }
   }
   while (sec < 4321);
}

void Timer::notifyAll()
{
   typedef std::vector<TimerObserver*>::iterator iter;
   int actualTimeInMin= 0;
   for (iter it= observers.begin(); it != observers.end(); ++it)
   {
      actualTimeInMin= actualTime * 4;
      (*it)->update(actualTimeInMin);   
   }     
}

Timer* Timer::getInstance()
{
   if(!instance)
      instance= new Timer();
   return instance;
}





