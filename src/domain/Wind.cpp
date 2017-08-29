#include "Wind.h"
#include "Data.h"
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

void Wind::updateDirection(const int& actualTime)
{
   Direction oldDirection= actualDirection; 
   do {
      actualDirection= static_cast<Direction>(rand() % 4);   
   } while (actualDirection == oldDirection);
   sendDateToReport(Data::getInstance(actualTime, Data::WIND_CHANGES));
}



