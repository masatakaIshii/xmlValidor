//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_ELEMENT_H
#define XMLVALIDOR_ELEMENT_H

#include <iostream>
#include <map>
#include "ChildElement.h"

class Element {
private:
    std::string name;
    std::map<std::string, ChildElement> children;
public:
    std::string getName();
    std::map<std::string, ChildElement> getChildren;
};

#endif //XMLVALIDOR_ELEMENT_H
