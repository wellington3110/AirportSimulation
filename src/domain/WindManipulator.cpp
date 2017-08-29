#include "WindManipulator.h"
#include "RandomNumberGenerator.h"
#include "Wind.h"

static WindManipulator* instance;

void WindManipulator::generateEventsToWind()
{
   for (int eventTime = 0; eventTime < 4321;) {
      eventTime += RandomNumberGenerator::generateNumberBetween(16, 40);
      windEventsTime.push(eventTime);
   }
}

WindManipulator* WindManipulator::getInstance()
{
   if(!instance)
      instance= new WindManipulator;
   return instance;
}

void WindManipulator::update(const int& actualTime)
{
   if(windEventsTime.size() > 0) {
      if(isValidUpdateStatusWind(actualTime)){
         windEventsTime.pop();
         Wind::getInstance()->updateDirection(actualTime);
      }
   }
}


