//
// Created by masat on 12/11/2020.
//

#include <gtest/gtest.h>
#include "../../../src/infrastructures/factories/ChildDtdFactory/ChildDtdFactoryRef.h"

using namespace factories;

namespace {
    class ChildDtdFactoryTests : public ::testing::Test {
    protected:
        ChildDtdFactory *childDtdFactory{};

        void SetUp() override {
            childDtdFactory = new ChildDtdFactoryRef();
        }

        void TearDown() override {
            delete childDtdFactory;
        }
    };

    TEST_F(ChildDtdFactoryTests, createElement_shouldCreateChildDtdRefAndReturnPointer) {
        ChildDtd *result = childDtdFactory->createChild("child name");

        ASSERT_NE(result, nullptr);
        EXPECT_EQ(typeid(*result).name(), typeid(ChildDtdRef).name());
        delete result;
    }

    TEST_F(ChildDtdFactoryTests, createElement_shouldCreateChildDtdWithOccurrenceOneByDefault) {
        ChildDtd *result = childDtdFactory->createChild("child name");

        ASSERT_NE(result, nullptr);
        EXPECT_EQ(result->getOccurrence(), OccurrenceChildDtd::One);
        delete result;
    }

    TEST_F(ChildDtdFactoryTests, createElement_shouldCreateChildDtdWithOccurrenceDefinedInParam) {
        ChildDtd *result = childDtdFactory->createChild("child name", OccurrenceChildDtd::ZeroOrMore);

        ASSERT_NE(result, nullptr);
        EXPECT_EQ(result->getOccurrence(), OccurrenceChildDtd::ZeroOrMore);
        delete result;
    }
}