#pragma once
#include "gtest/gtest.h"
#include "Simulator.h"

class MainTest : public testing::Test
{
protected:

};

TEST_F(MainTest,FakeMain)
{
   Simulator s;
   s.run(10);
}