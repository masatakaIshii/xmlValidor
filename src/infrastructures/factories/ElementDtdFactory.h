//
// Created by masat on 02/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTDTDFACTORY_H
#define XMLVALIDOR_ELEMENTDTDFACTORY_H

#include <iostream>
#include "../../models/ElementDtd/ElementDtdRef.h"
#include "ChildDtdFactory.h"

class ElementDtdFactory {
private:
    ChildDtdFactory *childDtdFactory{};
public:
    ElementDtdFactory();

    ElementDtd *createElement(std::string name);
};

#endif //XMLVALIDOR_ELEMENTDTDFACTORY_H
