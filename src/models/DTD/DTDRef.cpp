//
// Created by masat on 01/11/2020.
//

#include "DTDRef.h"
#include "ElementDtdNotFoundException.h"

using namespace models;

DTDRef::DTDRef(std::string filePath) : filePath(std::move(filePath)) {
}

std::string DTDRef::getFilePath() {
    return this->filePath;
}

std::map<std::string, ElementDtd *> DTDRef::getElementsMap() {
    return this->elements;
}

void DTDRef::addElement(ElementDtd *element) {
    if (element == nullptr) throw std::invalid_argument("element is null");
    this->elements.insert({element->getName(), element});
}

ElementDtd *DTDRef::getElementByName(const std::string &name) {
    auto itr = this->elements.find(name);
    if (itr == this->elements.end()) {
        throw ElementDtdNotFoundException("ElementDtd with name '" + name + "' not found");
    }
    return itr->second;
}

DTDRef::~DTDRef() {
    for (auto &it : this->elements) {
        delete it.second;
    }
    this->elements.clear();
}
