#pragma once
#include "gtest/gtest.h"
#include "Wind.h"

class WindTest : public testing::Test
{
protected:
   Wind* wind;
   std::vector<Wind::Direction>* directions;

   virtual void SetUp()
   {
      directions= new std::vector<Wind::Direction>;
      wind= Wind::getInstance();
   }

   virtual void TearDown()
   {
      delete directions;
   }

   void addAllDirectionsInVector() const
   {
      directions->push_back(Wind::Direction::NORTH_SOUTH);
      directions->push_back(Wind::Direction::LEST_WEST);
      directions->push_back(Wind::Direction::NORTHEAST_SOUTHWEST);
      directions->push_back(Wind::Direction::NORTHWEST_SOUTHEAST);   
   }
   
   bool compareActualDirectionWithAllDirections(std::vector<Wind::Direction>& directions) const
   {
      typedef std::vector<Wind::Direction>::iterator iter;
      for (iter it= directions.begin(); it != directions.end(); ++it) {
         *it == wind->getDirection();
         return true;
      }
      return false;
   }
};

TEST_F(WindTest, shouldBeTheSameInstance)
{
   Wind* wind1= Wind::getInstance();
   Wind* wind2= Wind::getInstance();
   ASSERT_TRUE(wind1 = wind2);
}

TEST_F(WindTest, makeSureEveryDirectionsAreChosenOnce)
{
   addAllDirectionsInVector();
   do {
      wind->randomlyChooseNewStatus();
      compareActualDirectionWithAllDirections(*directions) ? directions->pop_back() : 0;
   } while (directions->size() > 0);
   ASSERT_TRUE(directions->size() == 0);
}
