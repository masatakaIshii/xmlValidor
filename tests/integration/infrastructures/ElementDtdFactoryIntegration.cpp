//
// Created by masat on 11/11/2020.
//

#include <gtest/gtest.h>
#include "../../../src/infrastructures/factories/ElementDtdFactory/ElementDtdFactoryRef.h"
#include "../../../src/models/ElementDtd/ElementDtdRef.h"

using namespace factories;

namespace integration {
    class ElementDtdFactoryIntegration : public ::testing::Test {
    protected:
        ElementDtdFactory *elementDtdFactory{};

        void SetUp() override {
            elementDtdFactory = new ElementDtdFactoryRef();
        }

        void TearDown() override {
            delete elementDtdFactory;
        }
    };

    TEST_F(ElementDtdFactoryIntegration, createElement_shouldCreateElementDtdRefAndReturnPointer) {
        ElementDtd *result = elementDtdFactory->createElement("element name");

        EXPECT_EQ(typeid(*result).name(), typeid(ElementDtdRef).name());
        delete result;
    }
}