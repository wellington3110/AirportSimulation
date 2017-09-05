#pragma once
#ifndef INCLUDED_TOWEROFCOMMAND_H
#define INCLUDED_TOWEROFCOMMAND_H

#include "TimerObserver.h"

class RunWay;
class Aircraft;

class TowerOfCommand : public TimerObserver
{
public:
   virtual ~TowerOfCommand() {}

   virtual void update(const int& actualTime) = 0;
   
   virtual void receiveLandingRequest(Aircraft* plane) = 0;
   virtual void receiveTakeOffRequest(Aircraft* plane) = 0; 
   virtual void receiveConfirmationLanding(Aircraft* plane) = 0;
   virtual void receiveConfirmationTakeOff(Aircraft* plane) = 0;
   
};


#endif
