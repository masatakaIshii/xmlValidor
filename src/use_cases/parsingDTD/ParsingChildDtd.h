//
// Created by masat on 12/11/2020.
//

#ifndef XMLVALIDOR_PARSINGCHILDDTD_H
#define XMLVALIDOR_PARSINGCHILDDTD_H

#include <iostream>
#include "../../models/ChildDtd/ChildDtd.h"

using namespace models;

namespace use_cases {
    class ParsingChildDtd {
    public:
        virtual ~ParsingChildDtd() = default;

        virtual ChildDtd *parseDtd(std::string) = 0;
    };
}


#endif //XMLVALIDOR_PARSINGCHILDDTD_H
