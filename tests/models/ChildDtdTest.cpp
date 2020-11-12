//
// Created by masat on 11/11/2020.
//

#include <gtest/gtest.h>
#include "../../src/models/ChildDtd/ChildDtdRef.h"

using namespace models;

namespace {
    class ChildDtdTest : public ::testing::Test {
    protected:
        ChildDtd *childDtd{};

        void SetUp() override {
            childDtd = new ChildDtdRef("child dtd test name");
        }

        void TearDown() override {
            delete childDtd;
        }
    };

    TEST_F(ChildDtdTest, shouldGetName) {
        std::string childDtdName = "child dtd test name";
        EXPECT_STREQ(childDtd->getName().c_str(), childDtdName.c_str());
    }

    TEST_F(ChildDtdTest, shouldOcurrenceOnByDefault) {
        EXPECT_EQ(childDtd->getOccurrence(), OccurrenceChildDtd::One);
    }

    TEST_F(ChildDtdTest, shouldHaveMinOneOccurrence) {
        delete childDtd;
        childDtd = new ChildDtdRef("childTest", OccurrenceChildDtd::MinOne);
        EXPECT_EQ(childDtd->getOccurrence(), OccurrenceChildDtd::MinOne);
    }

    TEST_F(ChildDtdTest, shouldHaveZeroOrMoreOccurrence) {
        delete childDtd;
        childDtd = new ChildDtdRef("childTest", OccurrenceChildDtd::ZeroOrMore);
        EXPECT_EQ(childDtd->getOccurrence(), OccurrenceChildDtd::ZeroOrMore);
    }

    TEST_F(ChildDtdTest, shouldHaveZeroOrOneOccurrence) {
        delete childDtd;
        childDtd = new ChildDtdRef("childTest", OccurrenceChildDtd::ZeroOrOne);
        EXPECT_EQ(childDtd->getOccurrence(), OccurrenceChildDtd::ZeroOrOne);
    }
}
