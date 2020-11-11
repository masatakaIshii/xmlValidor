//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_DTD_H
#define XMLVALIDOR_DTD_H

#include <iostream>
#include <map>
#include "ElementDtd/ElementDtdRef.h"
#include "../infrastructures/factories/ElementDtdFactory.h"
#include "../infrastructures/factories/ChildDtdFactory.h"

class DTD {
private:
    std::string filePath;
    std::map<std::string, ElementDtd *> elements;
public:
    explicit DTD(std::string filePath);

    ~DTD();

    std::string getFilePath();

    ElementDtd *getElementByName(const std::string &name);

    void addElement(ElementDtd *element);
};

#endif //XMLVALIDOR_DTD_H
