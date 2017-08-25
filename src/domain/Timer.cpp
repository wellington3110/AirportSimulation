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
      if(actualTime > sec) {
         notifyAll();
         sec ++;
         std::cout << sec << std::endl;
      }
   }
   while (sec < 20); // alterar para o tempo correto dps
}

void Timer::notifyAll()
{
   
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





