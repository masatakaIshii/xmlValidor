//
// Created by masat on 11/11/2020.
//

#ifndef XMLVALIDOR_CHILDDTD_H
#define XMLVALIDOR_CHILDDTD_H

#include <iostream>
#include <vector>
#include "OccurrenceChildDtd.h"

namespace models {
    class ChildDtd {
    public:
        virtual ~ChildDtd() = default;

        virtual std::string getName() = 0;

        virtual std::vector<std::string> getNames() = 0;

        virtual void addName(std::string) = 0;

        virtual OccurrenceChildDtd getOccurrence() = 0;

        virtual void setOccurrence(OccurrenceChildDtd occurrenceChildDtd) = 0;
    };
}

#endif //XMLVALIDOR_CHILDDTD_H
