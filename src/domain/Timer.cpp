#include "Timer.h"
#include "TimerObserver.h"
#include<ctime>
#include <iostream>

static Timer* instance;

void Timer::start()
{
   int sec= 0;
   do {
      actualTime= clock()/CLOCKS_PER_SEC;
     if (actualTime > sec) {
         notifyAll();
         sec ++;
         std::cout << sec << std::endl;;
      }
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





