#pragma once
#ifndef INCLUDED_TIMEOBSERVER_H
#define INCLUDED_TIMEOBSERVER_H

class TimerObserver
{
public:
   virtual ~TimerObserver() {};
   virtual void update(const int& actualTime) = 0;   
};

#endif
