#pragma once
#ifndef INCLUDED_SIMULATOR_H
#define INCLUDED_SIMULATOR_H

class Simulator
{
public:
   ~Simulator();

   static Simulator* getInstance();

   void stop();
   void run(int planesOnLand);
   
private:
   Simulator() {}
   Simulator(const Simulator&);

   void addObserversOfTimer(int planesOnLand); 
   
};

#endif
