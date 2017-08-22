#pragma once
#include "gtest/gtest.h"
#include "Wind.h"
#include "RunWay.h"

class RunWayTest : public testing::Test
{
protected:
   Wind* wind;
   RunWay* runWay;

   virtual void SetUp()
   {
      runWay= nullptr;
      wind= Wind::getInstance();
   }
   
   virtual void TearDown()
   {
      delete runWay;
   }

   void assertThatRunWayIsBlocked()
   {
      instanceRunWayWithOpositeInitialWindDirection();
      ASSERT_FALSE(runWay->isFree());    
   }

   void setWindWithSameDirectionOfRunWay()
   {
      while ( !runWay->isFree() )
      {
         wind->randomlyChooseNewStatus();
         runWay->verifyWind();
      }
   }

   void instanceRunWayWithOpositeInitialWindDirection()
   {
      Wind::Direction opositeInitialWindDirecion= Wind::LEST_WEST;
      runWay= new RunWay(wind, opositeInitialWindDirecion);   
   }
};

TEST_F(RunWayTest, actualStatusShouldBeFree)
{
   Wind::Direction initialWindDirection= wind->getDirection();
   runWay= new RunWay(wind, initialWindDirection);
   ASSERT_TRUE(runWay->isFree());
}

TEST_F(RunWayTest, actualStatusShouldBeBlockedByWind)
{
   assertThatRunWayIsBlocked();  
}

TEST_F(RunWayTest, shouldChangeActualStatusRunWayToFree)
{
   assertThatRunWayIsBlocked();
   setWindWithSameDirectionOfRunWay();
   ASSERT_TRUE(runWay->isFree());
}
