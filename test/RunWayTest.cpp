#pragma once
#include "gtest/gtest.h"
#include "Wind.h"
#include "RunWay.h"
#include "RunWayTest.h"

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
      setWindDirectionAsNorthSouth();
      delete runWay;
   }

   void setWindDirectionAsNorthSouth()
   {
      while (wind->getDirection() != Wind::NORTH_SOUTH)
         wind->randomlyChooseNewStatus();
   }

   void instaceRunWayAsFreeAndChangeToUsing()
   {
      instanceRunWayWithSameInitialWindDirection();
      runWay->changeStatusToPlaneUsingRunWay();
   }

   void setWindWithSameDirectionOfRunWay()
   {
      while ( !runWay->isFree() )
      {
         wind->randomlyChooseNewStatus();
         runWay->verifyWind();
      }
   }

   void instanceRunWayWithSameInitialWindDirection()
   {
      Wind::Direction initialWindDirection = wind->getDirection();
      runWay = new RunWay(wind, initialWindDirection);
   }

   void instanceRunWayWithOpositeInitialWindDirection()
   {
      Wind::Direction opositeInitialWindDirecion= Wind::LEST_WEST;
      runWay= new RunWay(wind, opositeInitialWindDirecion);   
   }
};

TEST_F(RunWayTest, actualStatusShouldBeFree)
{
   instanceRunWayWithSameInitialWindDirection();
   ASSERT_TRUE(runWay->isFree());
}

TEST_F(RunWayTest, actualStatusShouldBeBlockedByWind)
{
   instanceRunWayWithOpositeInitialWindDirection();
   ASSERT_FALSE(runWay->isFree());
}

TEST_F(RunWayTest, shouldChangeActualStatusFromBlockedToFree)
{
   instanceRunWayWithOpositeInitialWindDirection();
   setWindWithSameDirectionOfRunWay();
   ASSERT_TRUE(runWay->isFree());
}

TEST_F(RunWayTest, shouldChangeActualStatusFromFreeToUsing) 
{
   instanceRunWayWithSameInitialWindDirection();
   ASSERT_TRUE(runWay->changeStatusToPlaneUsingRunWay());
   EXPECT_EQ(RunWay::PLANE_USING_RUNWAY, runWay->getActualStatus());
}

TEST_F(RunWayTest, shouldChangeActualStatusFromUsingToFree)
{
   instaceRunWayAsFreeAndChangeToUsing();
   ASSERT_TRUE(runWay->changeStatusToRunWayFree());
   ASSERT_TRUE(runWay->isFree());
}

TEST_F(RunWayTest, shouldNotChangeActualStatusFromUsingToFree)
{
   instaceRunWayAsFreeAndChangeToUsing();
   runWay->verifyWind();
   ASSERT_FALSE(runWay->isFree());
}

TEST_F(RunWayTest, shouldNotChangeActualStatusFromBlockedToFree)
{
   instanceRunWayWithOpositeInitialWindDirection();
   ASSERT_FALSE(runWay->changeStatusToRunWayFree());
   ASSERT_FALSE(runWay->changeStatusToPlaneUsingRunWay());
}




