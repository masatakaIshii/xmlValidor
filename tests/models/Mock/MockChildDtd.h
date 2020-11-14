//
// Created by masat on 11/11/2020.
//

#ifndef XMLVALIDOR_MOCKCHILDDTD_H
#define XMLVALIDOR_MOCKCHILDDTD_H

#include <gmock/gmock.h>
#include "../../../src/models/ChildDtd/ChildDtd.h"

using namespace models;

class MockChildDtd : public ChildDtd {
public:
    MOCK_METHOD(std::string, getName, (), (override));
    MOCK_METHOD(std::vector<std::string>, getNames, (), (override));
    MOCK_METHOD(void, addName, (std::string name), (override));
    MOCK_METHOD(OccurrenceChildDtd, getOccurrence, (), (override));
    MOCK_METHOD(void, setOccurrence, (OccurrenceChildDtd), (override));

    ~MockChildDtd() override = default;
};

#endif //XMLVALIDOR_MOCKCHILDDTD_H
