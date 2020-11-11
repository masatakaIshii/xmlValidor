//
// Created by masat on 01/11/2020.
//

#include "ElementDtdRef.h"

using namespace models;

ElementDtdRef::ElementDtdRef(std::string name) : name(std::move(name)) {
}

std::string ElementDtdRef::getName() {
    return this->name;
}

std::map<std::string, ChildDtd *> ElementDtdRef::getChildren() {
    return std::map<std::string, ChildDtd *>();
}

void ElementDtdRef::addChildDtd(ChildDtd *childDtd) {

}

ChildDtd *ElementDtdRef::getChildByName(std::string) {
    return nullptr;
}

ElementDtdRef::~ElementDtdRef() {

}
