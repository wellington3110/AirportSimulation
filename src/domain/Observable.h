#pragma once
#ifndef INCLUDED_OBSERVABLE_H
#define INCLUDED_OBSERVABLE_H

class TimerObserver;

class Observable
{
public:
   virtual ~Observable() {};
   virtual void add(TimerObserver* observer) = 0;
   virtual void notifyAll() = 0;
};

#endif