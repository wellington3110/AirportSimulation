#include "Timer.h"
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
   for (iter it= observers.begin(); it != observers.end(); ++it)
      (*it)->update(actualTime * 4);
}

Timer* Timer::getInstance()
{
   if(!instance)
      instance= new Timer();
   return instance;
}





