#pragma once
#include "Observable.h"

class ObservableMock : public Observable
{
public:
   ObservableMock() : allNotified(false), countObservers(0) {}
   
   bool expectations(int amount, bool notified);
   bool getAllNotified() const { return allNotified; }
   int getCountObserver() const { return  countObservers; }

   virtual void notifyAll();
   virtual void add(TimerObserver* observer) { countObservers++; }   

private:
   int countObservers;
   bool allNotified;
};


inline void ObservableMock::notifyAll()
{
   if (countObservers > 0) allNotified = true;
}

bool ObservableMock::expectations(int amount, bool notified)
{
   bool expectation= (amount == countObservers) && (notified == allNotified);
   return expectation;
}
