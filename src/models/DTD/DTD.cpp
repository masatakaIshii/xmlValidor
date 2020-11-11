//
// Created by masat on 01/11/2020.
//

#include "DTD.h"

DTD::DTD(std::string filePath) {
    this->filePath = std::move(filePath);
}

std::string DTD::getFilePath() {
    return this->filePath;
}

ElementDtd *DTD::getElementByName(const std::string &name) {
    auto itr = this->elements.find(name);
    if (itr->first != name) {
        std::cerr << "Problem to find element in elements" << std::endl;
    }
    return itr->second;
}

void DTD::addElement(ElementDtd *element) {
//    this->elements.insert({element->getName(), element});
}

DTD::~DTD() = default;
