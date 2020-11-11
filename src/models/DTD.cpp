//
// Created by masat on 01/11/2020.
//

#include "DTD.h"

#include <utility>

DTD::DTD(std::string filePath, ElementDtdFactory elementDtdFactory, ChildDtdFactory childDtdFactory) {
    this->filePath = std::move(filePath);
    this->elementDtdFactory = elementDtdFactory;
    this->childDtdFactory = childDtdFactory;
}

std::string DTD::getFilePath() {
    return this->filePath;
}

ElementDtd DTD::getElementByName(const std::string& name) {
    auto itr = this->elements.find(name);
    if (itr->first != name) {
        std::cerr << "Problem to find element in elements" << std::endl;
    }
    return itr->second;
}

void DTD::addElement(std::string elementName) {
    ElementDtd newElement = this->elementDtdFactory.createElement(std::move(elementName));
    this->addElement(newElement);
}

void DTD::addElement(ElementDtd element) {
    this->elements.insert({element.getName(), element});
}
