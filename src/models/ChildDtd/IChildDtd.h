//
// Created by masat on 11/11/2020.
//

#ifndef XMLVALIDOR_ICHILDDTD_H
#define XMLVALIDOR_ICHILDDTD_H

#include <iostream>
#include "OccurrenceChildDtd.h"

namespace models {
    class IChildDtd {
    public:
        virtual std::string getName() = 0;

        virtual OccurrenceChildDtd getOccurrence() = 0;
    };
}

#endif //XMLVALIDOR_ICHILDDTD_H
