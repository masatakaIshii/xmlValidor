//
// Created by masat on 12/11/2020.
//

#include <gtest/gtest.h>
#include "../../src/models/DTD/DTDRef.h"
#include "Mock/MockElementDtd.h"
#include "../../src/models/DTD/ElementDtdNotFoundException.h"

using ::testing::AtLeast;
using ::testing::Return;

namespace {
    class DTDTest : public ::testing::Test {
    protected:
        DTD *dtd{};

        void SetUp() override {
            dtd = new DTDRef("filepath.txt");
        }

        void TearDown() override {
            delete dtd;
        }
    };

    TEST_F(DTDTest, getFilePath_shouldReturnFilePath) {
        EXPECT_STREQ(dtd->getFilePath().c_str(), "filepath.txt");
    }

    TEST_F(DTDTest, getElementsMap_shouldReturnMapOfElementNameAndPointer) {
        auto elements = dtd->getElementsMap();
        EXPECT_EQ(typeid(elements).name(), typeid(std::map<std::string, ElementDtd *>).name());
    }

    TEST_F(DTDTest, addElement_shouldAddElementInMapElements) {
        auto mockElementDtd = new MockElementDtd();
        auto result = dtd->getElementsMap();
        EXPECT_CALL(*mockElementDtd, getName())
                .Times(1)
                .WillOnce(Return("MockElement"));
        EXPECT_EQ(result.size(), 0);

        dtd->addElement(mockElementDtd);
        result = dtd->getElementsMap();

        EXPECT_EQ(result.size(), 1);
    }

    TEST_F(DTDTest, addElement_whenElementNull_shouldThrowException) {
        ASSERT_THROW(dtd->addElement(nullptr), std::invalid_argument);
        try {
            dtd->addElement(nullptr);
        } catch (std::invalid_argument &e) {
            EXPECT_STREQ(e.what(), "element is null");
        }
    }

    TEST_F(DTDTest, getElementByName_whenNameCorrespondToOneElement_shouldReturnElement) {
        auto mockElementDtd = new MockElementDtd();
        EXPECT_CALL(*mockElementDtd, getName())
                .WillOnce(Return("MockElement"));
        dtd->addElement(mockElementDtd);

        auto resultElement = dtd->getElementByName("MockElement");

        EXPECT_EQ(resultElement, mockElementDtd);
    }

    TEST_F(DTDTest, getElementByName_whenFewElementsInDtd_shouldReturnConcernedElement) {
        auto mockElementDtd1 = new MockElementDtd();
        auto mockElementDtd2 = new MockElementDtd();
        EXPECT_CALL(*mockElementDtd1, getName())
        .WillOnce(Return("MockElement1"));
        EXPECT_CALL(*mockElementDtd2, getName())
        .WillOnce(Return("MockElement2"));
        dtd->addElement(mockElementDtd1);
        dtd->addElement(mockElementDtd2);

        auto resultElement2 = dtd->getElementByName("MockElement2");
        auto resultElement1 = dtd->getElementByName("MockElement1");

        EXPECT_EQ(resultElement1, mockElementDtd1);
        EXPECT_EQ(resultElement2, mockElementDtd2);
    }

    TEST_F(DTDTest, getElementByName_whenNameIsNotInElements_shouldThrowException) {
        auto mockElementDtd1 = new MockElementDtd();
        EXPECT_CALL(*mockElementDtd1, getName())
                .WillOnce(Return("MockElement1"));
        dtd->addElement(mockElementDtd1);

        ASSERT_THROW(dtd->getElementByName("NotMockElement"), ElementDtdNotFoundException);
        try {
            dtd->getElementByName("Nop");
        } catch (ElementDtdNotFoundException &e) {
            EXPECT_STREQ(e.what(), "ElementDtd with name 'Nop' not found");
        }
    }
}
