#include "Wind.h"
#include <cstdlib>

//////////////////////////////////////////////////
static Wind* instance;

Wind* Wind::getInstance()
{
   if(!instance)
      instance= new Wind;
   return instance;
}
/////////////////////////////////////////////////

void Wind::randomlyChooseNewStatus()
{
   actualDirection= static_cast<Direction>(rand() % 4);
}



