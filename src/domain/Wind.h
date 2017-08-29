#pragma once
#ifndef INCLUDED_WIND_H
#define INCLUDED_WIND_H

#include <vector>
#include "DataVendorToReport.h"

class WindObservers;

class Wind : public DataVendorToReport
{
public:
   enum Direction {
      NORTH_SOUTH, LEST_WEST, NORTHEAST_SOUTHWEST,
      NORTHWEST_SOUTHEAST 
   };
   
   static Wind* getInstance();
   
   void updateDirection(const int& actualTime);
   Direction& getDirection() { return actualDirection; }

private:
   Wind() : DataVendorToReport(), actualDirection(NORTH_SOUTH) {}
   Wind(const Wind&);

   Direction actualDirection;
   std::vector<WindObservers*> observers;
};

#endif 