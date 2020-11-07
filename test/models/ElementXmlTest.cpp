//
// Created by Mikadows on 01/11/2020.
//

#include <gtest/gtest.h>
#include <iostream>

#include "../../src/models/ElementXml.h"

namespace {
    TEST(ElementXmlTest, isValidNominal) {
        auto elementXml = new ElementXml("NameTest", "ContentTest");
        EXPECT_EQ(true, elementXml->isValid());
    }

    TEST(ElementXmlTest, isValidNameEmpty) {
        auto elementXml = new ElementXml("", "ContentTest");
        EXPECT_EQ(false, elementXml->isValid());
    }

    TEST(ElementXmlTest, isValidContentEmpty) {
        auto elementXml = new ElementXml("NameTest", "");
        EXPECT_EQ(false, elementXml->isValid());
    }

    TEST(ElementXmlTest, getNameNominal) {
        auto elementXml = new ElementXml("NameTest", "ContentTest");
        EXPECT_EQ("NameTest", elementXml->getName());
    }

    TEST(ElementXmlTest, getContentNominal) {
        auto elementXml = new ElementXml("NameTest", "ContentTest");
        EXPECT_EQ("ContentTest", elementXml->getContent());
    }

    TEST(ElementXmlTest, equalsNominal) {
        auto elementXml1 = new ElementXml("NameTest", "ContentTest");
        auto elementXml2 = new ElementXml("NameTest", "ContentTest");
        EXPECT_EQ(true, elementXml1->equals(*elementXml2));
    }

    TEST(ElementXmlTest, equalsNotEquals) {
        auto elementXml1 = new ElementXml("NameTest", "ContentTest");
        auto elementXml2 = new ElementXml("Toto", "ContentTest");
        EXPECT_EQ(false, elementXml1->equals(*elementXml2));
    }

//    TEST(ElementXmlTest, getChildrenNominal) {
//        auto elementXml = new ElementXml("NameTest", "ContentTest");
//        auto elementXml2 = new ElementXml(" ", " ");
//        elementXml->addChild(*elementXml2);
//        std::vector<ElementXml> arr = elementXml->getChildren();
//
//
//        EXPECT_EQ(arr, elementXml->getChildren());
//    }



}