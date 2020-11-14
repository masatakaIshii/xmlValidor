//
// Created by masat on 02/11/2020.
//

#ifndef XMLVALIDOR_CHILDELEMENTFACTORY_H
#define XMLVALIDOR_CHILDELEMENTFACTORY_H

#include <iostream>
#include "../../../models/ChildDtd/ChildDtdRef.h"
#include "ChildDtdFactory.h"

using namespace models;

namespace factories {
    class ChildDtdFactoryRef : public ChildDtdFactory {
    public:
        ChildDtdFactoryRef();

        ChildDtd *createChild(std::string name) override;

        ChildDtd *createChild(std::string name, OccurrenceChildDtd occurrence) override;

        ChildDtd *createChild(
                std::string name,
                OccurrenceChildDtd occurrence,
                bool hasOnlyOneName) override;
    };
}

#endif //XMLVALIDOR_CHILDELEMENTFACTORY_H
