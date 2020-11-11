#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../../src/use_cases/example_gtest/Turtle.h"
#include "../../../src/use_cases/example_gtest/Painter.h"
#include "Mock/MockTurtle.h"

//
// Created by masat on 07/11/2020.
//
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::Ge;
using ::testing::Le;
using ::testing::InSequence;
using ::testing::AnyNumber;

class PainterTests : public ::testing::Test {
protected:
    MockTurtle mockTurtle;
    Painter *painter;

    void SetUp() override {
        painter = new Painter(&mockTurtle);
    }

    void TearDown() override {
        delete painter;
    }
};

TEST_F(PainterTests, CanDrawSometing) {
    EXPECT_CALL(mockTurtle, PenDown())
            .Times(AtLeast(1));

    EXPECT_TRUE(painter->DrawCircle(0, 0, 10));
}

TEST_F(PainterTests, testTurtleGetX) {
    EXPECT_CALL(mockTurtle, GetX())
            .Times(5)
            .WillOnce(Return(100))
            .WillOnce(Return(150))
            .WillRepeatedly(Return(200));

    EXPECT_EQ(painter->testGetX(), 850);
}

TEST_F(PainterTests, testForward) {
    EXPECT_CALL(mockTurtle, Forward(200));

    painter->testForward(200);
}

TEST_F(PainterTests, testGoToSequently) {
    {
        InSequence seq;
        EXPECT_CALL(mockTurtle, GoTo(Ge(50), _))
                .Times(2);
        EXPECT_CALL(mockTurtle, GoTo(_, Le(30)));
        EXPECT_CALL(mockTurtle, GoTo(_, _))
                .Times(AnyNumber());
    }
    painter->testGoTo();
}

TEST_F(PainterTests, testGoToSpecificCalls) {
    EXPECT_CALL(mockTurtle, GoTo(_, _))
            .Times(AnyNumber());

    EXPECT_CALL(mockTurtle, GoTo(Ge(50), 99999))
            .Times(3);

    painter->testGoTo();
}

TEST_F(PainterTests, testThrowWhenForwardNegativeNumber) {
    ASSERT_THROW(painter->testForward(-1), std::invalid_argument);
    try {
        painter->testForward(-1);
    } catch (std::invalid_argument &e) {
        EXPECT_STREQ(e.what(), "distance have to be not negative number");
    }
}

TEST_F(PainterTests, testGetXCalls) {
    for (int i = 5; i > 0; i--) {
        EXPECT_CALL(mockTurtle, GetX())
                .WillOnce(Return(10 * i))
                .RetiresOnSaturation();
    }
    EXPECT_EQ(painter->testGetX(), 150);
}