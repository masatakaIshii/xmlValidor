//
// Created by masat on 12/11/2020.
//

#ifndef XMLVALIDOR_CHILDDTDFACTORY_H
#define XMLVALIDOR_CHILDDTDFACTORY_H

#include <string>
#include "../../../models/ChildDtd/ChildDtd.h"

using namespace models;

namespace factories {
    class ChildDtdFactory {
    public:
        virtual ~ChildDtdFactory() = default;

        virtual ChildDtd *createChild(std::string name) = 0;

        virtual ChildDtd *createChild(std::string, OccurrenceChildDtd occurrence) = 0;

        virtual ChildDtd *createChild(
                std::string name,
                OccurrenceChildDtd occurrence,
                bool hasOnlyOneName
        ) = 0;
    };
}

#endif //XMLVALIDOR_CHILDDTDFACTORY_H
