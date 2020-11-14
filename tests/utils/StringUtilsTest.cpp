//
// Created by masat on 13/11/2020.
//

#include <gtest/gtest.h>
#include "../../src/utils/StringUtils.h"

using namespace utils;

namespace {
    class StringUtilsTest : public ::testing::Test {
    };

    TEST_F(StringUtilsTest, splitShouldReturnStringVector) {
        auto result = StringUtils::split("test", "");
        EXPECT_STREQ(typeid(result).name(), typeid(std::vector<std::string>).name());
    }

    TEST_F(StringUtilsTest, split_whenTextNoContainOneCharSeparator_shouldNotSplitToTwoNames) {
        auto result = StringUtils::split("tonton1,test2", "!");
        ASSERT_EQ(result.size(), 1);
        EXPECT_STREQ(result[0].c_str(), "tonton1,test2");
    }

    TEST_F(StringUtilsTest, split_whenTextHasOneCharSeparator_shouldSplitToTwoNames) {
        auto result = StringUtils::split("tonton1,test2", ",");
        ASSERT_EQ(result.size(), 2);
        EXPECT_STREQ(result[0].c_str(), "tonton1");
        EXPECT_STREQ(result[1].c_str(), "test2");
    }

    TEST_F(StringUtilsTest, split_whenTextHasStringSeparator_shouldSplitToTwoNames) {
        auto result = StringUtils::split("tonton1 * test2", " * ");
        ASSERT_EQ(result.size(), 2);
        EXPECT_STREQ(result[0].c_str(), "tonton1");
        EXPECT_STREQ(result[1].c_str(), "test2");
    }

    TEST_F(StringUtilsTest, split_whenTextHasNoStringSeparator_shouldNotSplitToTwoNames) {
        auto result = StringUtils::split("tonton1--test2", "---");
        ASSERT_EQ(result.size(), 1);
        EXPECT_STREQ(result[0].c_str(), "tonton1--test2");
    }

    TEST_F(StringUtilsTest, split_whenDelimiterIsEmpty_shouldSplitOfVectorOfCharacters) {
        auto result = StringUtils::split("te-st", "");
        ASSERT_EQ(result.size(), 5);
        EXPECT_STREQ(result[0].c_str(), "t");
        EXPECT_STREQ(result[1].c_str(), "e");
        EXPECT_STREQ(result[2].c_str(), "-");
        EXPECT_STREQ(result[3].c_str(), "s");
        EXPECT_STREQ(result[4].c_str(), "t");
    }
}