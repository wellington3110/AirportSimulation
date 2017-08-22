#include "Airport.h"


static TowerOfCommand* instance;

TowerOfCommand* Airport::getInstance()
{
   if(!instance)
      instance= new Airport;
   return instance;
}
