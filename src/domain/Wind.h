#pragma once
#ifndef INCLUDED_WIND_H
#define INCLUDED_WIND_H

#include <vector>

class WindObservers;

class Wind
{
public:
   enum Direction {
      NORTH_SOUTH, LEST_WEST, NORTHEAST_SOUTHWEST,
      NORTHWEST_SOUTHEAST 
   };
   
   static Wind* getInstance();
   
   void chooseRandomlyNewDirection();
   Direction& getDirection() { return actualDirection; }

private:
   Wind() : actualDirection(NORTH_SOUTH) {}
   Wind(const Wind& c) {}

   Direction actualDirection;
   std::vector<WindObservers*> observers;
};

#endif 