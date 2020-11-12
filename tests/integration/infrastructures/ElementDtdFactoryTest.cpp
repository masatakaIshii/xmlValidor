//
// Created by masat on 11/11/2020.
//



#include <gtest/gtest.h>
#include "../../../src/infrastructures/factories/ElementDtdFactory.h"

namespace {
    class ElementDtdFactoryTests : public ::testing::Test {
    protected:
        ElementDtdFactory *elementDtdFactory;

        void SetUp() override {
            elementDtdFactory = new ElementDtdFactory();
        }

        void TearDown() override {
            delete elementDtdFactory;
        }
    };

    TEST_F(ElementDtdFactoryTests, createElement_shouldCreateElementDtdRefAndReturnPointer) {
        ElementDtd *result = elementDtdFactory->createElement("element name");

        EXPECT_EQ(typeid(*result).name(), typeid(ElementDtdRef).name());
        delete result;
    }
}
