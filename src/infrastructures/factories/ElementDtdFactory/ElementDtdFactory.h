//
// Created by masat on 12/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTDTDFACTORY_H
#define XMLVALIDOR_ELEMENTDTDFACTORY_H

#include <iostream>
#include "../../../models/ElementDtd/ElementDtd.h"

using namespace models;

namespace factories {
    class ElementDtdFactory {
    public:
        virtual ~ElementDtdFactory() = default;
        virtual ElementDtd *createElement(std::string name) = 0;
    };
}
#endif //XMLVALIDOR_ELEMENTDTDFACTORY_H
