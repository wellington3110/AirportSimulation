#include "Wind.h"
#include "Data.h"
#include <cstdlib>
#include "WindLog.h"

//////////////////////////////////////////////////
static Wind* instance;

Wind* Wind::getInstance()
{
   if(!instance)
      instance= new Wind(WindLog::getInstance());
   return instance;
}
/////////////////////////////////////////////////

void Wind::updateDirection(const int& actualTime)
{
   Direction oldDirection= actualDirection; 
   do {
      actualDirection= static_cast<Direction>(rand() % 4);   
   } while (actualDirection == oldDirection);
   windLog->generateLog(Log::WIND_DIRECTION, "");
   sendDateToReport(Data::createData(actualTime, Data::WIND_CHANGES));
}



