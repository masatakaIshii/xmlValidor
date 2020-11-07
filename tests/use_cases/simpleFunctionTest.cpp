//
// Created by masat on 27/10/2020.
//
#include "../../src/use_cases/simpleFunction.h"
#include <gtest/gtest.h>

namespace {
    TEST(SimpleFunctionTest, AddPositiveNumber) {
        EXPECT_EQ(2, addition(1, 1));
        EXPECT_EQ(4, addition(3, 1));
    }

    TEST(SimpleFunctionTest, AddNegativeNumber) {
        EXPECT_EQ(5, addition(7, -2));
        EXPECT_EQ(-10, addition(3, -13));
    }
}
