#pragma once
#ifndef INCLUDED_TOWEROFCOMMANDSTUMB_H
#define INCLUDED_TOWEROFCOMMANDSTUMB_H

#include "TowerOfCommand.h"

class TowerOfCommandStumb : public TowerOfCommand
{
public:
   virtual void update(const int& actualTime){}

   virtual void receiveLandingRequest(Aircraft* plane) {}
   virtual void receiveTakeOffRequest(Aircraft* plane) {}
   virtual void receiveConfirmationLanding(Aircraft* plane) {}
   virtual void receiveConfirmationTakeOff(Aircraft* plane) {}

private:

};


#endif 

