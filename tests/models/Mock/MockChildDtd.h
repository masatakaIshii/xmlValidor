//
// Created by masat on 11/11/2020.
//

#ifndef XMLVALIDOR_MOCKCHILDDTD_H
#define XMLVALIDOR_MOCKCHILDDTD_H

#include <gmock/gmock.h>
#include "../../../src/models/ChildDtd/IChildDtd.h"

using namespace models;

class MockChildDtd : public IChildDtd {
public:
    MOCK_METHOD(std::string, getName, (), (override));
    MOCK_METHOD(OccurrenceChildDtd, getOccurrence, (), (override));
};

#endif //XMLVALIDOR_MOCKCHILDDTD_H