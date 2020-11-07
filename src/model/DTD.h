//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_DTD_H
#define XMLVALIDOR_DTD_H

#include <iostream>
#include <map>
#include "Element.h"

class DTD {
private:
    std::string filePath;
    std::map <std::string, Element> elements;
public:
    DTD(std::string filePath, );
    std::string getFilePath();
    Element getElementByName(std::string name);
    void addElement(Element element);
};

#endif //XMLVALIDOR_DTD_H
