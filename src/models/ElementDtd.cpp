//
// Created by masat on 01/11/2020.
//

#include "ElementDtd.h"

ElementDtd::ElementDtd(std::string name, ChildDtdFactory &childDtdFactory) {
    this->name = std::move(name);
    this->childDtdFactory = childDtdFactory;
}

std::string ElementDtd::getName() {
    return this->name;
}

