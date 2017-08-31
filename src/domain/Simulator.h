#pragma once
#ifndef INCLUDED_SIMULATOR_H
#define INCLUDED_SIMULATOR_H

class Simulator
{
public:
   ~Simulator();
   void run(int planesOnLand);
   
private:
   void addObserversOfTimer(int planesOnLand); 
   
};

#endif
