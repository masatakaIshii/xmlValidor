//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_DTD_H
#define XMLVALIDOR_DTD_H

#include <iostream>
#include <map>
#include "ElementDtd.h"
#include "../infrastructures/factories/ElementDtdFactory.h"
#include "../infrastructures/factories/ChildDtdFactory.h"

class DTD {
private:
    std::string filePath;
    std::map <std::string, ElementDtd> elements;
    ElementDtdFactory elementDtdFactory;
    ChildDtdFactory childDtdFactory;
public:
    explicit DTD(std::string filePath, ElementDtdFactory elementDtdFactory, ChildDtdFactory childDtdFactory);
    std::string getFilePath();
    ElementDtd getElementByName(const std::string& name);
    void addElement(ElementDtd element);
    void addElement(std::string elementName);
};

#endif //XMLVALIDOR_DTD_H
