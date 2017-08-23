#pragma once

#include "gtest/gtest.h"
#include "AircraftFake.h"

class AircraftTest : public testing::Test
{
protected:
   AircraftFake* plane;

   virtual void SetUp()
   {
      plane= new AircraftFake;            
   }

   virtual void TearDown()
   {
      delete plane;
   } 

};

TEST_F(AircraftTest, makeSureThatMethodReceivePermissionToLandIsInvoked)
{
   plane->receivePermissionToLand();
   ASSERT_TRUE(plane->getActualStatus() == Aircraft::LANDING);
}

TEST_F(AircraftTest, makeSureThatMethodReceivePermissionToTakeOffIsInvoked)
{
   plane->receivePermissionToTakeOff();
   ASSERT_TRUE(plane->getActualStatus() == Aircraft::TAKING_OFF);
}

TEST_F(AircraftTest, makeSureThatMethodUpdateIsInvoked)
{
   plane->update(2);
   ASSERT_TRUE(plane->updateCall);
}



