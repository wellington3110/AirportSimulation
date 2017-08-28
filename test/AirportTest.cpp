//#pragma once
//
//#include "gtest/gtest.h"
//#include "TowerOfCommand.h"
//#include "Airport.h"
//#include "Plane.h"
//#include "AircraftManipulator.h"
//
//class AirportTest : public testing::Test
//{
//protected:
//   int timeOnLandStandard;
//   TowerOfCommand* airport;
//   std::vector<Aircraft*> planes;
//   std::vector<TimerObserver*> observers;
//
//   virtual void SetUp()
//   {
//      timeOnLandStandard= 20;
//      airport= Airport::getInstance(2);
//      observers.push_back(airport);
//   }
//
//   virtual void TearDown()
//   {
//      delete airport;
//   }
//
//   void ifOddAddMoreOne(int& minutes)
//   {
//      if ( !(minutes % 2 == 0) ) minutes+=1;
//   }
//
//   void speedTimeIn(int minutes)
//   {
//      ifOddAddMoreOne(minutes);
//      int realTime= minutes/4;
//      for (int i= 0; i < realTime; ++i) {
//         for (std::vector<TimerObserver*>::iterator iter = observers.begin(); iter != observers.end(); ++iter)
//            if(*iter)
//               (*iter)->update(1);
//      }
//   }
//
//   void toLandPlanes(int times) 
//   {
//      for (int i= 0; i < times; i++) {
//         Aircraft* newPlane = new Plane(airport, timeOnLandStandard);
//         planes.push_back(newPlane);
//         observers.push_back(newPlane);
//         speedTimeIn(12);
//      }
//   }
//
//   void toBeginPlanesTakeOff(int times)
//   {
//      for (int i= 0; i < times; i++) {
//         toLandPlanes(times);
//         speedTimeIn(timeOnLandStandard);
//      }
//   }
//
//   void toTakeOffPlanes(int times)
//   {
//      for (int i = 0; i < times; ++i) {
//         toBeginPlanesTakeOff(times);
//         speedTimeIn(12);
//      }
//   }
// 
//   void addPlanes(int amount, int timeOnLand) 
//   {
//      for (int i= 0; i < amount; i++) {
//         Aircraft* newPlane= new Plane(airport, timeOnLand);
//         planes.push_back(newPlane);
//         observers.push_back(newPlane);
//      }            
//   }
//
//   Aircraft::AircraftStatus isEqual(Aircraft::AircraftStatus expectStatus) 
//   {
//      return expectStatus;
//   }
//
//   void assertThat(Aircraft::AircraftStatus actualStatus, Aircraft::AircraftStatus expectStatus)
//   {
//      ASSERT_TRUE(expectStatus == actualStatus);
//   }
//   
//};
//
//TEST_F(AirportTest, airportShouldReleaseRunWayForPlaneToLand)
//{
//   addPlanes(1, 20);
//   assertThat(planes.front()->getActualStatus(), isEqual(Aircraft::LANDING));
//}
//                                                      
//TEST_F(AirportTest, airportShouldReleaseRunWayForPlaneToTakeOff)
//{
//   toBeginPlanesTakeOff(1);
//   assertThat(planes.front()->getActualStatus(), isEqual(Aircraft::TAKING_OFF));
//}
//
//TEST_F(AirportTest, aiportShouldNotReleaseRunWayForPlaneToLand) 
//{
//   addPlanes(2, 20);
//   assertThat(planes.back()->getActualStatus(), isEqual(Aircraft::REQUESTING_LANDING));
//}
//
//TEST_F(AirportTest, airportShouldNotReleaseRunWayForPlaneToTakeOff) 
//{
//   toLandPlanes(3);
//   assertThat(planes.front()->getActualStatus(), isEqual(Aircraft::REQUESTING_TAKE_OFF));
//}
//
//TEST_F(AirportTest, airportShouldSendPlaneToAnotherAirport) 
//{
//   addPlanes(4, 20);
//   speedTimeIn(32);
//   assertThat(planes.back()->getActualStatus(), isEqual(Aircraft::SENT_ANOTHER_AIRPORT));
//}
//
//TEST_F(AirportTest, planeShouldHasCompletedTakeOff)
//{
//   toTakeOffPlanes(1);
//   assertThat(planes.front()->getActualStatus(), isEqual(Aircraft::TOOK_OFF));
//}
//
//TEST_F(AirportTest, planeShouldNotToLandDueThePlanesOnLand)
//{
//   addPlanes(3, 20);
//   speedTimeIn(26);
//   assertThat(planes.back()->getActualStatus(), isEqual(Aircraft::REQUESTING_LANDING));
//}
//
//TEST_F(AirportTest, planeShouldHasCompletedLanding)
//{
//   toLandPlanes(1);
//   assertThat(planes.front()->getActualStatus(), isEqual(Aircraft::ON_LAND));
//}









