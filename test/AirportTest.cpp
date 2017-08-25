#pragma once

#include "gtest/gtest.h"
#include "TowerOfCommand.h"
#include "Airport.h"
#include "Plane.h"

class AirportTest : public testing::Test
{
protected:
   const int timeOnLandStandard= 20;
   TowerOfCommand* airport;
   std::vector<Aircraft*> planes;
   std::vector<TimerObserver*> observers;

   virtual void SetUp()
   {
      airport= Airport::getInstance(10);
      observers.push_back(airport);
   }

   virtual void TearDown()
   {
      delete airport;
   }

   void ifOddAddMoreOne(int& minutes)
   {
      if ( !(minutes % 2 == 0) ) minutes+=1;
   }

   void speedTimeIn(int minutes)
   {
      ifOddAddMoreOne(minutes);
      int realTime= minutes/4;
      for (int i= 0; i < realTime; ++i) {
         for (std::vector<TimerObserver*>::iterator iter = observers.begin(); iter != observers.end(); ++iter) {
            if ((*iter) != nullptr)
               (*iter)->update(1);
            else
               observers.erase(iter);
         }
            
      }
   }

   void toLandPlanes(int times) 
   {
      for (int i= 0; i < times; i++) {
         Aircraft* newPlane = new Plane(airport, timeOnLandStandard);
         planes.push_back(newPlane);
         observers.push_back(newPlane);
         speedTimeIn(12);
      }
   }

   void toBeginPlanesTakeOff(int times)
   {
      for (int i= 0; i < times; i++) {
         toLandPlanes(times);
         speedTimeIn(timeOnLandStandard);
      }
   }

   void assertThatWasDeleted(Aircraft* plane) 
   {
      if (plane)
         FAIL("It should be deleted");
      else
         SUCCEED("It was deleted");
   }
 
   void addPlanes(int amount, int timeOnLand) 
   {
      for (int i= 0; i < amount; i++) {
         Aircraft* newPlane= new Plane(airport, timeOnLand);
         planes.push_back(newPlane);
         observers.push_back(newPlane);
      }            
   }

   Aircraft::AircraftStatus isEqual(Aircraft::AircraftStatus expectStatus) 
   {
      return expectStatus;
   }

   void assertThat(Aircraft::AircraftStatus actualStatus, Aircraft::AircraftStatus expectStatus)
   {
      EXPECT_EQ(expectStatus, actualStatus);
   }
   
};

TEST_F(AirportTest, airportShouldReleaseRunWayForPlaneToLand)
{
   addPlanes(1, 20);
   assertThat(planes.front()->getActualStatus(), isEqual(Aircraft::LANDING));
}
                                                      
TEST_F(AirportTest, airportShouldReleaseRunWayForPlaneToTakeOff)
{
   toBeginPlanesTakeOff(1);
   assertThat(planes.front()->getActualStatus(), isEqual(Aircraft::TAKING_OFF));
}

TEST_F(AirportTest, aiportShouldNotReleaseRunWayForPlaneToLand) 
{
   addPlanes(2, 20);
   assertThat(planes.back()->getActualStatus(), isEqual(Aircraft::REQUESTING_LANDING));
}

TEST_F(AirportTest, airportShouldNotReleaseRunWayForPlaneToTakeOff) 
{
   toLandPlanes(3);
   assertThat(planes.front()->getActualStatus(), isEqual(Aircraft::REQUESTING_TAKE_OFF));
}

TEST_F(AirportTest, airportShouldSendPlaneToAnotherAirport) 
{
   addPlanes(5, 20);
   speedTimeIn(32);
   assertThatWasDeleted(planes.back());
}




