#pragma once
#ifndef INCLUDED_TIMEROBSERVER_H
#define INCLUDED_TIMEROBSERVER_H

class TimerObserver
{
public:
   virtual ~TimerObserver() {};
   virtual void update(const int& actualTime) = 0;   
};

#endif
