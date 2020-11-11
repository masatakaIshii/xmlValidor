//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_CHILDDTDREF_H
#define XMLVALIDOR_CHILDDTDREF_H

#include <iostream>
#include "ChildDtd.h"

namespace models {
    class ChildDtdRef : public ChildDtd {
    private:
        std::string name;
        OccurrenceChildDtd occurrence;
    public:
        explicit ChildDtdRef(std::string name, OccurrenceChildDtd occurrence = OccurrenceChildDtd::One);

        ~ChildDtdRef() override;

        std::string getName() override;

        OccurrenceChildDtd getOccurrence() override;
    };
}

#endif //XMLVALIDOR_CHILDDTDREF_H
