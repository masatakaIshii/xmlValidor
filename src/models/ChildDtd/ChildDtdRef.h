//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_CHILDDTDREF_H
#define XMLVALIDOR_CHILDDTDREF_H

#include <iostream>
#include <vector>
#include "ChildDtd.h"

namespace models {
    class ChildDtdRef : public ChildDtd {
    private:
        std::vector<std::string> names;
        OccurrenceChildDtd occurrence;
        bool hasOnlyOneName;
    public:
        explicit ChildDtdRef(const std::string& name, OccurrenceChildDtd occurrence = OccurrenceChildDtd::One, bool hasOnlyOneName = true);

        ~ChildDtdRef() override;

        std::string getName() override;

        std::vector<std::string> getNames() override;

        void addName(std::string name) override;

        OccurrenceChildDtd getOccurrence() override;

        void setOccurrence(OccurrenceChildDtd occurrenceChildDtd) override;
    };
}

#endif //XMLVALIDOR_CHILDDTDREF_H
