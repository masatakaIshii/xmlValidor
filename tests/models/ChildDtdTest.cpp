//
// Created by masat on 11/11/2020.
//

#include <gtest/gtest.h>
#include "../../src/models/ChildDtd.h"

using namespace models;

namespace {
    class ChildDtdTest : public ::testing::Test {

    };

    TEST_F(ChildDtdTest, shouldGetName) {
        std::string childDtdName = "child dtd test name";
        ChildDtd childDtd(childDtdName);
        EXPECT_STREQ(childDtd.getName().c_str(), childDtdName.c_str());
    }

    TEST_F(ChildDtdTest, shouldOcurrenceOnByDefault) {
        ChildDtd childDtd("name");
        EXPECT_EQ(childDtd.getOccurrence(), Occurrence::One);
    }

    TEST_F(ChildDtdTest, shouldHaveMinOneOccurrence) {
        ChildDtd childDtd("childTest", Occurrence::MinOne);
        EXPECT_EQ(childDtd.getOccurrence(), Occurrence::MinOne);
    }

    TEST_F(ChildDtdTest, shouldHaveZeroOrMoreOccurrence) {
        ChildDtd childDtd("childTest", Occurrence::ZeroOrMore);
        EXPECT_EQ(childDtd.getOccurrence(), Occurrence::ZeroOrMore);
    }

    TEST_F(ChildDtdTest, shouldHaveZeroOrOneOccurrence) {
        ChildDtd childDtd("childTest", Occurrence::ZeroOrOne);
        EXPECT_EQ(childDtd.getOccurrence(), Occurrence::ZeroOrOne);
    }
}

