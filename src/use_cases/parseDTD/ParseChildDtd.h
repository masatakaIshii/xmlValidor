//
// Created by masat on 12/11/2020.
//

#ifndef XMLVALIDOR_PARSECHILDDTDTEST_H
#define XMLVALIDOR_PARSECHILDDTDTEST_H

#include <iostream>
#include "../../models/ChildDtd/ChildDtd.h"

using namespace models;

namespace use_cases {
    class ParseChildDtd {
    public:
        virtual ~ParseChildDtd() = default;

        virtual ChildDtd *parseChildDtd(std::string) = 0;
    };
}


#endif //XMLVALIDOR_PARSECHILDDTDTEST_H
