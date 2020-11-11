//
// Created by masat on 11/11/2020.
//

#include <gtest/gtest.h>
#include "../../src/models/ElementDtd/ElementDtdRef.h"
#include "Mock/MockChildDtd.h"

using namespace models;

namespace {
    class ElementDtdTest : public ::testing::Test {

    };

    TEST_F(ElementDtdTest, shouldGetName) {
        std::string elementDtdName = "elementTest";
        ElementDtdRef elementDtdTest(elementDtdName);
        EXPECT_STREQ(elementDtdTest.getName().c_str(), elementDtdName.c_str());
    }

    TEST_F(ElementDtdTest, shouldAddChildDtdAndGetMapChildren) {
        MockChildDtd mockChildDtd;
        ElementDtdRef elementDtdTest("elementTest");
        auto children = elementDtdTest.getChildren();

        elementDtdTest.addChildDtd(&mockChildDtd);
        EXPECT_EQ(children.size(), 0);

        children = elementDtdTest.getChildren();
        EXPECT_EQ(children.size(), 1);
    }
}