#pragma once
#ifndef INCLUDED_OBSERVERMOCK_H
#define INCLUDED_OBSERVERMOCK_H

#include "TimerObserver.h"

class ObserverMock : public TimerObserver
{
public:
   ~ ObserverMock(){}
   virtual void update(int& actualTime)
   {
      if(actualTime == 8)
      {
         throw CountedToEightMinutesExpection();
      }   
   }

   class CountedToEightMinutesExpection : public std::exception
   {}; 
   
};

#endif

