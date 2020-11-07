//
// Created by masat on 02/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTFACTORY_H
#define XMLVALIDOR_ELEMENTFACTORY_H

#include <iostream>
#include "../../model/ElementDtd.h"

class ElementFactory {
public:
    ElementFactory();
    ElementDtd createElement(std::name, ChildDtdFactory &childDtdFactory);
};

#endif //XMLVALIDOR_ELEMENTFACTORY_H
