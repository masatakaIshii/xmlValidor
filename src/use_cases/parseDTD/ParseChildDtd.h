//
// Created by masat on 12/11/2020.
//

#ifndef XMLVALIDOR_PARSECHILDDTD_H
#define XMLVALIDOR_PARSECHILDDTD_H

#include <iostream>
#include "../../models/ChildDtd/ChildDtd.h"

using namespace models;

namespace use_cases {
    class ParseChildDtd {
    public:
        virtual ~ParseChildDtd() = default;

        virtual ChildDtd *parseChildDtd(const std::string &childContent) = 0;
    };
}


#endif //XMLVALIDOR_PARSECHILDDTD_H
