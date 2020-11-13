//
// Created by masat on 13/11/2020.
//

#include <gtest/gtest.h>
#include "../../../src/use_cases/parsingDTD/ParsingChildDtd.h"
#include "../../../src/use_cases/parsingDTD/ParsingChildDtdRef.h"
#include "../../infrastructures/Mock/MockChildDtdFactory.h"

using namespace use_cases;

namespace {
    class ParsingChildDtdTest : public ::testing::Test {
    protected:
        ParsingChildDtd *parsingChildDtd{};
        MockChildDtdFactory *mockChildDtdFactory{};

        void SetUp() override {
            mockChildDtdFactory = new MockChildDtdFactory();
            parsingChildDtd = new ParsingChildDtdRef(mockChildDtdFactory);
        }

        void TearDown() override {
            delete parsingChildDtd;
        }
    };

    TEST_F(ParsingChildDtdTest, parseDtd_when) {

    }
}