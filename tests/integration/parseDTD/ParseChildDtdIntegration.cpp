//
// Created by masat on 14/11/2020.
//

#include <gtest/gtest.h>
#include "../../../src/use_cases/parseDTD/ParseChildDtd.h"
#include "../../../src/use_cases/parseDTD/ParseChildDtdRef.h"
#include "../../../src/infrastructures/factories/ChildDtdFactory/ChildDtdFactoryRef.h"

using namespace use_cases;
using namespace models;

namespace integration {
    class ParseChildDtdIntegration : public ::testing::Test {
    protected:
        ChildDtd *childDtd{};
        ChildDtdFactory *childDtdFactory{};
        ParseChildDtd *parseChildDtd{};

        void SetUp() override {
            childDtd = nullptr;
            childDtdFactory = new ChildDtdFactoryRef();
            parseChildDtd = new ParseChildDtdRef(childDtdFactory);
        }

        void TearDown() override {
            delete parseChildDtd;
            delete childDtd;
        }
    };

    TEST_F(ParseChildDtdIntegration, parseChildDtd_shouldCanCreateChildOneOrMoreName) {
        childDtd = parseChildDtd->parseChildDtd("classroom+");

        ASSERT_NE(childDtd, nullptr);
        EXPECT_EQ(childDtd->getOccurrence(), OccurrenceChildDtd::MinOne);
        EXPECT_STREQ(childDtd->getName().c_str(), "classroom");
    }

    TEST_F(ParseChildDtdIntegration, parseChildDtd_shouldCanCreateChildZeroOrMoreOccurrenceAndNames) {
        childDtd = parseChildDtd->parseChildDtd("(#PCDATA|to|from|header|message)*");
        std::vector<std::string> expectedNames;
        expectedNames = {"#PCDATA", "to", "from", "header", "message"};

        ASSERT_NE(childDtd, nullptr);
        auto names = childDtd->getNames();

        EXPECT_EQ(childDtd->getOccurrence(), OccurrenceChildDtd::ZeroOrMore);
        for (int i = 0; i < names.size(); i++) {
            EXPECT_STREQ(names[i].c_str(), expectedNames[i].c_str());
        }
    }
}