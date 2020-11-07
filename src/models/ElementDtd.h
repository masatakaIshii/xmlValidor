//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTDTD_H
#define XMLVALIDOR_ELEMENTDTD_H

#include <iostream>
#include <map>
#include "ChildDtd.h"
#include "../infrastructures/factories/ChildDtdFactory.h"

class ElementDtd {
private:
    std::string name;
    ChildDtdFactory childDtdFactory;
    std::map<std::string, ChildDtd> children;
public:
    ElementDtd(std::string name, ChildDtdFactory &childDtdFactory);
    std::string getName();
    std::map<std::string, ChildDtd> getChildren;
};

#endif //XMLVALIDOR_ELEMENTDTD_H
