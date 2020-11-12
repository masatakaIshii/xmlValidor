//
// Created by masat on 11/11/2020.
//

#include <gtest/gtest.h>
#include "../../src/models/ElementDtd/ElementDtdRef.h"
#include "Mock/MockChildDtd.h"
#include "../../src/models/ElementDtd/ChildDtdNotFoundException.h"

using ::testing::AtLeast;
using ::testing::Return;

namespace {
    class ElementDtdTest : public ::testing::Test {
    protected:
        ElementDtd *elementDtd{};

        void SetUp() override {
            elementDtd = new ElementDtdRef("elementTest");
        }

        void TearDown() override {
            delete elementDtd;
        }
    };

    TEST_F(ElementDtdTest, shouldGetName) {
        std::string elementDtdName = "elementTest";
        ElementDtdRef elementDtdTest(elementDtdName);
        EXPECT_STREQ(elementDtdTest.getName().c_str(), elementDtdName.c_str());
    }

    TEST_F(ElementDtdTest, getChildren_shouldGetMapOfChildNameAndChildDtdPointer) {
        ElementDtdRef elementDtdTest("elementTest");
        auto children = elementDtdTest.getChildren();

        EXPECT_STREQ(typeid(children).name(), typeid(std::map<std::string, ChildDtd *>).name());
    }

    TEST_F(ElementDtdTest, addChildDtd_shouldAddChildDtdInChildrenMap) {
        auto mockChildDtd = new MockChildDtd();
        ElementDtdRef elementDtdTest("elementTest");
        auto children = elementDtdTest.getChildren();

        EXPECT_CALL(*mockChildDtd, getName())
                .Times(1)
                .WillOnce(Return("MockChild"));

        EXPECT_EQ(children.size(), 0);

        elementDtdTest.addChildDtd(mockChildDtd);

        children = elementDtdTest.getChildren();
        EXPECT_EQ(children.size(), 1);
    }

    TEST_F(ElementDtdTest, getChildByName_whenOneChildDtdHasName_shouldReturnPointerChildDtd) {
        auto mockChildDtd1 = new MockChildDtd();
        auto mockChildDtd2 = new MockChildDtd();
        ElementDtdRef elementDtdTest("elementTest");
        auto children = elementDtdTest.getChildren();

        EXPECT_CALL(*mockChildDtd1, getName())
                .WillRepeatedly(Return("MockChild1"));
        EXPECT_CALL(*mockChildDtd2, getName())
                .WillRepeatedly(Return("MockChild2"));
        EXPECT_EQ(children.size(), 0);

        elementDtdTest.addChildDtd(mockChildDtd1);
        elementDtdTest.addChildDtd(mockChildDtd2);

        children = elementDtdTest.getChildren();
        EXPECT_EQ(children.size(), 2);

        auto resultChildDtd1 = elementDtdTest.getChildByName("MockChild1");
        auto resultChildDtd2 = elementDtdTest.getChildByName("MockChild2");

        ASSERT_NE(resultChildDtd1, nullptr);
        ASSERT_NE(resultChildDtd2, nullptr);
        EXPECT_STREQ(resultChildDtd1->getName().c_str(), "MockChild1");
        EXPECT_STREQ(resultChildDtd2->getName().c_str(), "MockChild2");
    }

    TEST_F(ElementDtdTest, getChildByName_whenNameIsNotChildName_shouldThrowError) {
        auto mockChildDtd1 = new MockChildDtd();
        ElementDtdRef elementDtdTest("elementTest");
        auto children = elementDtdTest.getChildren();
        EXPECT_CALL(*mockChildDtd1, getName())
                .WillRepeatedly(Return("MockChild1"));
        elementDtdTest.addChildDtd(mockChildDtd1);

        ASSERT_THROW(elementDtdTest.getChildByName("NotAChildDtd"), ChildNotFoundException);
        try {
            elementDtdTest.getChildByName("NotAChildDtd");
        } catch (ChildNotFoundException &e) {
            EXPECT_STREQ(e.what(), "childDtd with name 'NotAChildDtd' not found");
        }
    }
}