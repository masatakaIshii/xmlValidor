//
// Created by Mikadows on 01/11/2020.
//

#include <gtest/gtest.h>

#include "../../src/models/ElementXml.h"

namespace {
    TEST(ElementXmlTest, isValidNominal) {
        auto *elementXml = new ElementXml("NameTest", "ContentTest");
        EXPECT_EQ(true, elementXml->isValid());
    }

    TEST(ElementXmlTest, isValidNameEmpty) {
        auto *elementXml = new ElementXml("", "ContentTest");
        EXPECT_EQ(false, elementXml->isValid());
    }

    TEST(ElementXmlTest, isValidContentEmpty) {
        auto *elementXml = new ElementXml("NameTest", "");
        EXPECT_EQ(false, elementXml->isValid());
    }

}