#pragma once
#ifndef INCLUDED_WIND_H
#define INCLUDED_WIND_H

#include <vector>
#include "DataVendorToReport.h"


class WindObservers;
class Log;

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
   Wind(Log* _windLog) : DataVendorToReport(), actualDirection(NORTH_SOUTH), windLog(_windLog) {}
   Wind(const Wind&);

   Direction actualDirection;
   std::vector<WindObservers*> observers;

   Log* windLog; 
};

#endif 