//
// Created by masat on 13/11/2020.
//

#ifndef XMLVALIDOR_MOCKCHILDDTDFACTORY_H
#define XMLVALIDOR_MOCKCHILDDTDFACTORY_H

#include <gmock/gmock.h>
#include "../../../src/infrastructures/factories/ChildDtdFactory/ChildDtdFactory.h"

using namespace factories;

class MockChildDtdFactory : public ChildDtdFactory {
public:
    MOCK_METHOD(ChildDtd*, createChild, (std::string), (override));
    MOCK_METHOD(ChildDtd*, createChild, (std::string, OccurrenceChildDtd), (override));
    MOCK_METHOD(ChildDtd*, createChild, (std::string, OccurrenceChildDtd, bool), (override));

    ~MockChildDtdFactory() override {}
};

#endif //XMLVALIDOR_MOCKCHILDDTDFACTORY_H
