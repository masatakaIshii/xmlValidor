//
// Created by masat on 11/11/2020.
//

#ifndef XMLVALIDOR_CHILDDTD_H
#define XMLVALIDOR_CHILDDTD_H

#include <iostream>
#include "OccurrenceChildDtd.h"

namespace models {
    class ChildDtd {
    public:
        virtual ~ChildDtd() = default;

        virtual std::string getName() = 0;

        virtual OccurrenceChildDtd getOccurrence() = 0;
    };
}

#endif //XMLVALIDOR_CHILDDTD_H
