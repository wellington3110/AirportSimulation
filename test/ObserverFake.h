#pragma once
#ifndef INCLUDED_OBSERVERFAKE_H
#define INCLUDED_OBSERVERFAKE_H

#include "TimerObserver.h"

class ObserverFake : public TimerObserver
{
public:

   virtual void update(int actualTime)
   {
      if(actualTime == 8)
      {
         throw CountedToEightMinutesException();
      }   
   }

   class CountedToEightMinutesException : public std::exception
   {}; 
   
};

#endif

