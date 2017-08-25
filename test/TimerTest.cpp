#pragma once
#ifndef INCLUDED_TIMERTEST_H
#define INCLUDED_TIMERTEST_H

#include "gtest/gtest.h"
#include "Observable.h"
#include "Timer.h"
#include "ObserverFake.h"

class TimerTest : public testing::Test
{
protected:
   Timer* timer;

   virtual void SetUp() {
      timer= Timer::getInstance();
   }

   void addObservers(int amount) {
      for (int i = 0; i < amount; ++i) 
         timer->add(new ObserverFake);          
   }
};

//TEST_F(TimerTest, shouldBeTheSameInstance) {
//   Observable* otherInstance= Timer::getInstance();
//   ASSERT_TRUE(timer == otherInstance);
//}
//
//TEST_F(TimerTest, shouldCountToEightMinutes)
//{
//   try {
//      addObservers(1);
//      timer->start();
//      FAIL("Should throw the expection");
//   } catch(ObserverFake::CountedToEightMinutesException& expection) {
//   }
//}



#endif

