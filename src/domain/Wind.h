#pragma once
#ifndef INCLUDED_WIND_H
#define INCLUDED_WIND_H

class Wind
{
public:
   enum Direction {
      NORTH_SOUTH, LEST_WEST, NORTHEAST_SOUTHWEST,
      NORTHWEST_SOUTHEAST 
   };

   Direction& getDirection() { return actualDirection; }
   static Wind* getInstance();
   void randomlyChooseNewStatus();

private:
   Wind() : actualDirection(NORTH_SOUTH) {}

   Direction actualDirection;
};

#endif 