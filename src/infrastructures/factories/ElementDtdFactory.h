//
// Created by masat on 02/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTDTDFACTORY_H
#define XMLVALIDOR_ELEMENTDTDFACTORY_H

#include <iostream>
#include "../../models/ElementDtd.h"

class ElementDtdFactory {
public:
    ElementDtdFactory();
    ElementDtd createElement(std::string name, ChildDtdFactory &childDtdFactory);
};

#endif //XMLVALIDOR_ELEMENTDTDFACTORY_H
