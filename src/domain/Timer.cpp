#include "Timer.h"
#include "TimerObserver.h"
#include<ctime>

static Timer* instance;

_CrtMemState s1, s2;

void Timer::start()
{
   int sec= 0;
   actualTime= 0;
   do {
      //actualTime= clock()/CLOCKS_PER_SEC;
      //if (actualTime > sec) {
         actualTime ++;
         notifyAll();
         sec ++;
      //}
   } while (sec < 1080);
}

void Timer::notifyAll()
{ 
   for (iter it= observers.begin(); it != observers.end(); ++it) 
      (*it)->update(actualTime * 4);   
}

Timer* Timer::getInstance()
{
   if(!instance)
      instance= new Timer();
   return instance;
}





