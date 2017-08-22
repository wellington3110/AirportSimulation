#pragma once

#include "gtest/gtest.h"
#include "AircraftMock.h"

class AircraftTest : public testing::Test
{
protected:
   AircraftMock* plane;
   TowerOfCommand* tower;

   virtual void SetUp()
   {
      plane= new AircraftMock;            
   }

   virtual void TearDown()
   {
      delete plane;
   } 

};

TEST_F(AircraftTest, planeShouldBeRequestingLanding)
{
   plane->sendLandingRequest(tower);
   EXPECT_EQ(Aircraft::REQUESTING_LANDING, plane->getActualStatus());
}

TEST_F(AircraftTest, planeShouldBeRequestingTakeOff)
{
   plane->sendTakeOffRequest(tower);
   EXPECT_EQ(Aircraft::REQUESTING_TAKE_OFF, plane->getActualStatus());
}

TEST_F(AircraftTest, planeShouldBeLanding)
{
   plane->sendLandingRequest(tower);
   plane->receivePermissionToLand();
   EXPECT_EQ(Aircraft::LANDING, plane->getActualStatus());
}

TEST_F(AircraftTest, planeShouldBeTakingOff)
{
   plane->sendTakeOffRequest(tower);
   plane->receivePermissionToTakeOff();
   EXPECT_EQ(Aircraft::TAKING_OFF, plane->getActualStatus());
}

TEST_F(AircraftTest, planeShouldOnLand)
{
   plane->sendLandingRequest(tower);
   plane->receivePermissionToLand();
   plane->confirmLanding(tower);
   ASSERT_TRUE(plane->expectationsAboutLanding());
}

TEST_F(AircraftTest, planeShouldTookOff)
{
   plane->sendTakeOffRequest(tower);
   plane->receivePermissionToTakeOff();
   plane->confirmTakeOff(tower);
   ASSERT_TRUE(plane->expectationsAboutTakeOff());
}

