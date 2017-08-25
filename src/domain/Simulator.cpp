#include "Simulator.h"
#include "Timer.h"
#include "Airport.h"
#include "AircraftManipulator.h"
#include "WindManipulator.h"

void Simulator::run(int planesOnLand)
{
   addObserversOfTimer(planesOnLand);
   Timer::getInstance()->start();
}

void Simulator::addObserversOfTimer(int planesOnLand)
{
   Timer::getInstance()->add(Airport::getInstance(planesOnLand));
   Timer::getInstance()->add(AircraftManipulator::getInstance());
   Timer::getInstance()->add(WindManipulator::getInstance());
}




