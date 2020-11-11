//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_CHILDDTD_H
#define XMLVALIDOR_CHILDDTD_H

#include <iostream>
#include "IChildDtd.h"

namespace models {
    class ChildDtd : public IChildDtd {
    private:
        std::string name;
        OccurrenceChildDtd occurrence;
    public:
        explicit ChildDtd(std::string name, OccurrenceChildDtd occurrence = OccurrenceChildDtd::One);

        ~ChildDtd();

        std::string getName() override;

        OccurrenceChildDtd getOccurrence() override;
    };
}

#endif //XMLVALIDOR_CHILDDTD_H
