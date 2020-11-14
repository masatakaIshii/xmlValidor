//
// Created by masat on 12/11/2020.
//

#include <gtest/gtest.h>
#include "../../../src/infrastructures/factories/ChildDtdFactory/ChildDtdFactoryRef.h"

using namespace factories;

namespace integration {
    class ChildDtdFactoryIntegration : public ::testing::Test {
    protected:
        ChildDtdFactory *childDtdFactory{};

        void SetUp() override {
            childDtdFactory = new ChildDtdFactoryRef();
        }

        void TearDown() override {
            delete childDtdFactory;
        }
    };

    TEST_F(ChildDtdFactoryIntegration, createElement_shouldCreateChildDtdRefAndReturnPointer) {
        ChildDtd *result = childDtdFactory->createChild("child name");

        ASSERT_NE(result, nullptr);
        EXPECT_EQ(typeid(*result).name(), typeid(ChildDtdRef).name());
        delete result;
    }

    TEST_F(ChildDtdFactoryIntegration, createElement_shouldCreateChildDtdWithOccurrenceOneByDefault) {
        ChildDtd *result = childDtdFactory->createChild("child name");

        ASSERT_NE(result, nullptr);
        EXPECT_EQ(result->getOccurrence(), OccurrenceChildDtd::One);
        delete result;
    }

    TEST_F(ChildDtdFactoryIntegration, createElement_shouldCreateChildDtdWithOccurrenceDefinedInParam) {
        ChildDtd *result = childDtdFactory->createChild("child name", OccurrenceChildDtd::ZeroOrMore);

        ASSERT_NE(result, nullptr);
        EXPECT_EQ(result->getOccurrence(), OccurrenceChildDtd::ZeroOrMore);
        delete result;
    }

    TEST_F(ChildDtdFactoryIntegration, createElement_shouldCreateChildDtdWithOccurrenceDefinedInParamAndCanSaveListNames) {
        ChildDtd *result = childDtdFactory->createChild(
                "child name",
                OccurrenceChildDtd::ZeroOrMore,
                false);

        ASSERT_NE(result, nullptr);
        EXPECT_STREQ(typeid(result->getNames()).name(), typeid(std::vector<std::string>).name());
        delete result;
    }
}