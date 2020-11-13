//
// Created by masat on 11/11/2020.
//

#include <gtest/gtest.h>
#include "../../src/models/ChildDtd/ChildDtdRef.h"
#include "../../src/models/ChildDtd/ChildDtdOnlyOneNameException.h"

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

    class ChildDtdSeveralNamesTest : public ::testing::Test {
    protected:
        ChildDtd *childDtd{};

        void SetUp() override {
            childDtd = new ChildDtdRef(
                    "child dtd with several names",
                    OccurrenceChildDtd::MinOne,
                    false);
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

    TEST_F(ChildDtdTest, setOccurrence_shouldSetOccurrence) {
        childDtd->setOccurrence(OccurrenceChildDtd::MinOne);
        EXPECT_NE(childDtd->getOccurrence(), OccurrenceChildDtd::One);
    }

    TEST_F(ChildDtdTest, shouldHaveMinOneOccurrence) {
        childDtd->setOccurrence(OccurrenceChildDtd::MinOne);
        EXPECT_EQ(childDtd->getOccurrence(), OccurrenceChildDtd::MinOne);
    }

    TEST_F(ChildDtdTest, shouldHaveZeroOrMoreOccurrence) {
        childDtd->setOccurrence(OccurrenceChildDtd::ZeroOrMore);
        EXPECT_EQ(childDtd->getOccurrence(), OccurrenceChildDtd::ZeroOrMore);
    }

    TEST_F(ChildDtdTest, shouldHaveZeroOrOneOccurrence) {
        childDtd->setOccurrence(OccurrenceChildDtd::ZeroOrOne);
        EXPECT_EQ(childDtd->getOccurrence(), OccurrenceChildDtd::ZeroOrOne);
    }

    TEST_F(ChildDtdTest, addName_whenChildDtdHasSeveralNamesBoolIsFalse_shouldThrowException) {
        ASSERT_THROW(childDtd->addName("test throw"), ChildDtdOnlyOneNameException);

        try {
            childDtd->addName("nop");
        } catch (ChildDtdOnlyOneNameException &e) {
            EXPECT_STREQ(e.what(), "This ChildDtd can has only one name");
        }
    }

    TEST_F(ChildDtdTest, getNames_whenChildDtdHasSeveralNamesBoolIsFalse_shouldThrowException) {
        ASSERT_THROW(childDtd->getNames(), ChildDtdOnlyOneNameException);

        try {
            childDtd->getNames();
        } catch (ChildDtdOnlyOneNameException &e) {
            EXPECT_STREQ(e.what(), "This ChildDtd can has only one name");
        }
    }

    TEST_F(ChildDtdSeveralNamesTest, getNames_shouldReturnVectorStringWithName) {
        auto names = childDtd->getNames();
        EXPECT_STREQ(typeid(names).name(), typeid(std::vector<std::string>).name());
    }

    TEST_F(ChildDtdSeveralNamesTest, getNames_shouldContainNamesAdded) {
        auto names = childDtd->getNames();
        EXPECT_EQ(names.size(), 1);

        childDtd->addName("Names1");
        names = childDtd->getNames();
        ASSERT_EQ(names.size(), 2);
        EXPECT_STREQ(names[1].c_str(), "Names1");

        childDtd->addName("the second names");
        names = childDtd->getNames();
        ASSERT_EQ(names.size(), 3);
        EXPECT_STREQ(names[2].c_str(), "the second names");
    }
}
