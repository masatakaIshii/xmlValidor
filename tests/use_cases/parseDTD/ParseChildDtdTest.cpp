//
// Created by masat on 13/11/2020.
//

//
// Created by masat on 13/11/2020.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../../src/use_cases/parseDTD/ParseChildDtd.h"
#include "../../../src/use_cases/parseDTD/ParseChildDtdRef.h"
#include "../../infrastructures/Mock/MockChildDtdFactory.h"
#include "../../models/Mock/MockChildDtd.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::InSequence;
using ::testing::AnyNumber;

using namespace use_cases;
using namespace models;

namespace {
    class ParseChildDtdTest : public ::testing::Test {
    protected:
        MockChildDtd mockChildDtd;
        ParseChildDtd *parseChildDtd{};
        MockChildDtdFactory *mockChildDtdFactory{};

        void SetUp() override {
            mockChildDtdFactory = new MockChildDtdFactory();
            parseChildDtd = new ParseChildDtdRef(mockChildDtdFactory);
        }

        void TearDown() override {
            delete parseChildDtd;
        }
    };

    TEST_F(ParseChildDtdTest, parseDtd_shouldCreateElementDtdByFactory) {
        std::string childDtdName = "testParseChildDtd";
        EXPECT_CALL(*mockChildDtdFactory,
                    createChild(childDtdName, OccurrenceChildDtd::One, true))
                .Times(1)
                .WillOnce(Return(&mockChildDtd));

        auto result = parseChildDtd->parseChildDtd(childDtdName);
        EXPECT_STREQ(typeid(*result).name(), typeid(mockChildDtd).name());
    }


    TEST_F(ParseChildDtdTest, parseDtd_whenNameEndWithPlusOperator_shouldCreateChildWithMinOneOccurrence) {
        std::string childDtdMinOneName = "testMinOneChild";
        EXPECT_CALL(*mockChildDtdFactory,
                    createChild(childDtdMinOneName, OccurrenceChildDtd::MinOne, true))
                .Times(1);
        parseChildDtd->parseChildDtd(childDtdMinOneName + "+");
    }

    TEST_F(ParseChildDtdTest, parseDtd_whenNameEndWithPlusOperator_shouldCreateChildWithZeroOrMoreOccurrence) {
        std::string childDtdZeroOrMoreName = "testZeroOrMoreChild";
        EXPECT_CALL(*mockChildDtdFactory,
                    createChild(childDtdZeroOrMoreName, OccurrenceChildDtd::ZeroOrMore, true))
                .Times(1);
        parseChildDtd->parseChildDtd(childDtdZeroOrMoreName + "*");
    }

    TEST_F(ParseChildDtdTest, parseDtd_whenNameEndWithPlusOperator_shouldCreateChildWithZeroOrOneOccurrence) {
        std::string childDtdZeroOrOneName = "testZeroOrMoreChild";
        EXPECT_CALL(*mockChildDtdFactory,
                    createChild(childDtdZeroOrOneName, OccurrenceChildDtd::ZeroOrOne, true))
                .Times(1);
        parseChildDtd->parseChildDtd(childDtdZeroOrOneName + "?");
    }

    TEST_F(ParseChildDtdTest, parseDtd_whenStringContainNames_shouldCreateChildWithHasOnlyOneNameToFalse) {
        std::string childDtdZeroOrOneName = "(first|second)";
        EXPECT_CALL(
                *mockChildDtdFactory,
                createChild("first", OccurrenceChildDtd::One, false))
                .Times(1)
                .WillOnce(Return(&mockChildDtd));
        EXPECT_CALL(
                mockChildDtd,
                addName(_))
                .Times(AnyNumber());
        parseChildDtd->parseChildDtd(childDtdZeroOrOneName);
    }

    TEST_F(ParseChildDtdTest, parseDtd_whenStringContainNames_shouldAddNames) {
        std::string childDtdOneWithNames = "(first|second|third)";
        EXPECT_CALL(
                *mockChildDtdFactory,
                createChild("first", OccurrenceChildDtd::One, false))
                .Times(1)
                .WillOnce(Return(&mockChildDtd));
        {
            InSequence seq;
            EXPECT_CALL(
                    mockChildDtd,
                    addName("second"))
                    .Times(1);
            EXPECT_CALL(
                    mockChildDtd,
                    addName("third"))
                    .Times(1);
        }

        parseChildDtd->parseChildDtd(childDtdOneWithNames);
    }

    TEST_F(ParseChildDtdTest, parseDtd_whenStringContainNamesWithOneOccurrence_shouldSetOccurrenceAndAddNames) {
        std::vector<std::string> childNames(4);
        childNames = {"#PCDATA", "to", "from", "header", "message"};
        EXPECT_CALL(
                *mockChildDtdFactory,
                createChild(childNames[0], OccurrenceChildDtd::ZeroOrMore, false))
                .Times(1)
                .WillOnce(Return(&mockChildDtd));
        {
            InSequence seq;
            for (int i = 1; i < childNames.size(); i++) {
                EXPECT_CALL(
                        mockChildDtd,
                        addName(childNames[i]))
                        .Times(1);
            }
        }

        parseChildDtd->parseChildDtd("(#PCDATA|to|from|header|message)*");
    }
}