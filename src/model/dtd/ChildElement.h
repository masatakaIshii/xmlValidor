//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_CHILDELEMENT_H
#define XMLVALIDOR_CHILDELEMENT_H

#include <iostream>

class ChildElement {
    std::string name;
    std::string occurrence;
public:
    std::string getName();
    std::string getOccurrence();
};

#endif //XMLVALIDOR_CHILDELEMENT_H
