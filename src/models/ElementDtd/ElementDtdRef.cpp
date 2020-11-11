//
// Created by masat on 01/11/2020.
//

#include "ElementDtdRef.h"
#include "ChildDtdNotFoundException.h"

using namespace models;

ElementDtdRef::ElementDtdRef(std::string name) : name(std::move(name)) {
}

std::string ElementDtdRef::getName() {
    return this->name;
}

std::map<std::string, ChildDtd *> ElementDtdRef::getChildren() {
    return this->children;
}

void ElementDtdRef::addChildDtd(ChildDtd *childDtd) {
    this->children.insert({childDtd->getName(), childDtd});
}

ChildDtd *ElementDtdRef::getChildByName(std::string childName) {
    if (this->children.find(childName) == this->children.end()) {
        throw ChildNotFoundException("childDtd with name '" + childName + "' not found");
    }
    return this->children.find(childName)->second;
}

ElementDtdRef::~ElementDtdRef() {
    std::map<std::string, ChildDtd *>::iterator it;

    for (it = this->children.begin(); it != this->children.end(); it++) {
        delete it->second;
    }
    this->children.clear();
}
