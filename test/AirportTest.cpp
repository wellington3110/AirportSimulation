#pragma once

#include "gtest/gtest.h"
#include "TowerOfCommand.h"
#include "Airport.h"
#include "Plane.h"

class AirportTest : public testing::Test
{
protected:
   TowerOfCommand* airport;
   std::vector<Aircraft*> planes;
   std::vector<TimerObserver*> observers;

   virtual void SetUp()
   {
      airport= Airport::getInstance(10);
      observers.push_back(airport);
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
         for(std::vector<TimerObserver*>::iterator iter= observers.begin(); iter != observers.end(); ++iter)
            (*iter)->update(1);
      }
   }
   
   void addPlanes(int amount, int timeOnLand) 
   {
      for (int i= 0; i < amount; i++) {
         Aircraft* newPlane= new Plane(airport, timeOnLand);
         planes.push_back(newPlane);
         observers.push_back(newPlane);
      }            
   }

   virtual void TearDown()
   {
      delete airport;
   }
};

TEST_F(AirportTest, airportShouldReleaseRunWayForPlaneToLand)
{
   addPlanes(1, 20);
   EXPECT_EQ(planes.front()->getActualStatus(), Aircraft::LANDING);
}
                                                      
TEST_F(AirportTest, airportShouldReleaseRunWayForPlaneToTakeOff)
{
   addPlanes(1, 20);
   speedTimeIn(32);//tempo para pousar e solicitar decolagem
   EXPECT_EQ(planes.front()->getActualStatus(), Aircraft::TAKING_OFF);
}

TEST_F(AirportTest, aiportShouldNotReleaseRunWayForPlaneToLand) {
   addPlanes(2, 20);
   EXPECT_EQ(planes.back()->getActualStatus(), Aircraft::REQUESTING_LANDING);
   // o segundo avião deve ir para a fila de espera porque as outras pistas estão bloqueadas pelo vento
}

TEST_F(AirportTest, airportShouldNotReleaseRunWayForPlaneToTakeOff) {
      
}




