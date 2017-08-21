#pragma once

#include "gtest/gtest.h"
#include "ObservableMock.h"
#include "ObserverMock.h"

class ObservableTest : public testing::Test
{
protected:
   ObservableMock* mock;

   virtual void SetUp() {
      mock= new ObservableMock;
   }

   virtual void TearDown() {
      delete mock;
   }

   void addObserverInMock(int amount) {
      for (int i = 0; i < amount; ++i) 
         mock->add(new ObserverMock);          
   }
};


TEST_F(ObservableTest, makeSureEverybodyWasNotified) {
   addObserverInMock(1);
   mock->notifyAll();
   EXPECT_EQ(true, mock->getAllNotified());
}

TEST_F(ObservableTest, makeSureThreeObserversWasAdded) {
   addObserverInMock(3);
   EXPECT_EQ(3, mock->getCountObserver());
}

TEST_F(ObservableTest, makeSureThatObserversWasNotifiedAndAdded) {
   addObserverInMock(5);
   mock->notifyAll();
   ASSERT_TRUE(mock->expectations(5, true));
}



