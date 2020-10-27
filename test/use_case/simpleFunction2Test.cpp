//
// Created by masat on 27/10/2020.
//

#include "../../src/use_case/simpleFunction2.h"
#include <gtest/gtest.h>

namespace {
    TEST(SimpleFunctionTest2, SubPositiveNumber) {
        EXPECT_EQ(0, sub(1, 1));
        EXPECT_EQ(2, sub(3, 1));
    }

    TEST(SimpleFunctionTest2, SubNegativeNumber) {
        EXPECT_EQ(9, sub(7, -2));
        EXPECT_EQ(16, sub(3, -13));
    }
}
