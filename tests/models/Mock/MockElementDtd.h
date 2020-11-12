//
// Created by masat on 12/11/2020.
//

#ifndef XMLVALIDOR_MOCKELEMENTDTD_H
#define XMLVALIDOR_MOCKELEMENTDTD_H

#include <gmock/gmock.h>
#include "../../../src/models/ElementDtd/ElementDtd.h"

using namespace models;

class MockElementDtd : public ElementDtd {
public:
    MOCK_METHOD(std::string, getName, (), (override));
    MOCK_METHOD(void, addChildDtd, (ChildDtd * ), (override));
    MOCK_METHOD((std::map<std::string, ChildDtd *>), getChildren, (), (override));
    MOCK_METHOD(ChildDtd*, getChildByName, (std::string), (override));

    ~MockElementDtd() override = default;
};

#endif //XMLVALIDOR_MOCKELEMENTDTD_H
