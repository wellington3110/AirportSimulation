#include "WindManipulator.h"
#include "Random.h"
#include "Wind.h"

static WindManipulator* instance;


WindManipulator::~WindManipulator()
{
   delete Wind::getInstance();
   instance= nullptr;
}

void WindManipulator::generateEventsToWind()
{
   for (int eventTime = 0; eventTime < 4320;) {
      eventTime += Random::generateNumberBetween(16, 40);
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
   if (isValidUpdateStatusWind(actualTime)) {
      windEventsTime.pop();
      Wind::getInstance()->updateDirection(actualTime);
   }
}


