//
// Created by masat on 01/11/2020.
//

#include "DTD.h"
#include "ElementDtdNotFoundException.h"

using namespace models;

DTD::DTD(std::string filePath) : filePath(std::move(filePath)) {
}

std::string DTD::getFilePath() {
    return this->filePath;
}

std::map<std::string, ElementDtd *> DTD::getElementsMap() {
    return this->elements;
}

void DTD::addElement(ElementDtd *element) {
    if (element == nullptr) throw std::invalid_argument("element is null");
    this->elements.insert({element->getName(), element});
}

ElementDtd *DTD::getElementByName(const std::string &name) {
    auto itr = this->elements.find(name);
    if (itr == this->elements.end()) {
        throw ElementDtdNotFoundException("ElementDtd with name '" + name + "' not found");
    }
    return itr->second;
}

DTD::~DTD() {
    for (auto &it : this->elements) {
        delete it.second;
    }
    this->elements.clear();
}
