#pragma once

#include "gtest/gtest.h"
#include "TowerOfCommand.h"
#include "Plane.h"
#include "TowerOfCommandDumie.h"


class PlaneTest : public testing::Test
{
protected:
   TowerOfCommand* airport;
   Aircraft* plane;


   virtual void SetUp()
   {
      airport= new TowerOfCommandDummie;
      plane= new Plane(airport, 0);
   }

   virtual void TearDown()
   {
      delete plane;
   } 

   void toLandPlane()
   {
      ASSERT_TRUE(plane->receivePermissionToLand());
      speedTimeIn(12);
   }

   void toTakeOffPlane()
   {
      changePlaneStatusToRequestTakeOffIn(35);
      ASSERT_TRUE(plane->receivePermissionToTakeOff());
   }

   void speedTimeIn(int minutes)
   {
      ifOddAddMoreOne(minutes);
      int realTime= minutes/4;
      for (int i= 0; i < realTime; ++i)
      {
         plane->updateStatus();   
      }
   }

   void instancePlane(int timeOnLand)
   {
      if(plane)
         delete plane;
      plane= new Plane(airport, timeOnLand);
   }
   
   void ifOddAddMoreOne(int& minutes)
   {
      if (!(minutes % 2 == 0)) minutes+=1;
   }

   void changePlaneStatusToRequestTakeOffIn(int minutes)
   {
      instancePlane(minutes);
      toLandPlane();
      speedTimeIn(minutes);   
   }

   void assertThatPlaneStatusIs(Aircraft::AircraftStatus expect)
   {
      EXPECT_EQ(expect, plane->getActualStatus());
   }

   

};

TEST_F(PlaneTest, planeShouldBeRequestingLanding)
{
   assertThatPlaneStatusIs(Aircraft::REQUESTING_LANDING);   
}

TEST_F(PlaneTest, planeShouldBeLanding)
{
   plane->receivePermissionToLand();
   assertThatPlaneStatusIs(Aircraft::LANDING);
}

TEST_F(PlaneTest, planeShouldBeOnLand)
{
   plane= new Plane(airport, 0);
   toLandPlane();
   assertThatPlaneStatusIs(Aircraft::ON_LAND);
}

TEST_F(PlaneTest, planeShouldBeRequestingTakeOffAfter20Minutes)
{
   changePlaneStatusToRequestTakeOffIn(20);
   assertThatPlaneStatusIs(Aircraft::REQUESTING_TAKE_OFF);
}

TEST_F(PlaneTest, planeShouldBeTakingOff)
{
   toTakeOffPlane();
   assertThatPlaneStatusIs(Aircraft::TAKING_OFF);
}

TEST_F(PlaneTest, planeShouldBeTookOff)
{
   toTakeOffPlane();
   speedTimeIn(12);
   assertThatPlaneStatusIs(Aircraft::TOOK_OFF);
}

TEST_F(PlaneTest, shouldNotBeAbleToChangeStatusToRequestingTakeOff)
{
   toLandPlane();
   ASSERT_FALSE(plane->receivePermissionToTakeOff());
}

TEST_F(PlaneTest, shouldNotBeAbleToChangeStatusToRequestingLanding)
{
   changePlaneStatusToRequestTakeOffIn(40);
   ASSERT_FALSE(plane->receivePermissionToLand());
}

 TEST_F(PlaneTest, planeShouldSentAnotherAirport)
{
   instancePlane(20);
   plane->receiveRequestToLandDenied();
   assertThatPlaneStatusIs(Aircraft::SENT_ANOTHER_AIRPORT);
}
