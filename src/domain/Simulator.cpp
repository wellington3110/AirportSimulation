#include "Simulator.h"
#include "Timer.h"
#include "Airport.h"
#include "AircraftManipulator.h"
#include "WindManipulator.h"


Simulator::~Simulator()
{
   delete Timer::getInstance();
   delete Airport::getInstance();
   delete AircraftManipulator::getInstance();
   delete WindManipulator::getInstance();
}

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




