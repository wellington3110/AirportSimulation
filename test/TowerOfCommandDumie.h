#ifndef INCLUDED_TOWEROFCOMMANDDUMIE
#define INCLUDED_TOWEROFCOMMANDDUMIE
#include "TowerOfCommand.h"

class TowerOfCommandDummie : public TowerOfCommand
{
public:
   virtual void update(int actualTime) {}
   
   virtual void receiveLandingRequest(Aircraft* plane){}
   virtual void receiveTakeOffRequest(Aircraft* plane){} 
   virtual void receiveConfirmationLanding(Aircraft* plane){}
   virtual void receiveConfirmationTakeOff(Aircraft* plane){}
};


#endif
