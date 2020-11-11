//
// Created by masat on 01/11/2020.
//

#include "ElementDtd.h"

using namespace models;

ElementDtd::ElementDtd(std::string name): name(std::move(name)) {
}

std::string ElementDtd::getName() {
    return this->name;
}

void ElementDtd::addChildDtd(ChildDtd *childDtd) {

}

ChildDtd *ElementDtd::getChildByName(std::string) {
    return nullptr;
}

