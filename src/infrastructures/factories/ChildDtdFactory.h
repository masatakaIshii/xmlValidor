//
// Created by masat on 02/11/2020.
//

#ifndef XMLVALIDOR_CHILDELEMENTFACTORY_H
#define XMLVALIDOR_CHILDELEMENTFACTORY_H

#include <iostream>
#include "../../models/ChildDtd/ChildDtdRef.h"
using namespace models;

class ChildDtdFactory {
public:
    ChildDtdFactory();
    ChildDtd* createChild(std::string name, OccurrenceChildDtd occurrence = OccurrenceChildDtd::One);
};

#endif //XMLVALIDOR_CHILDELEMENTFACTORY_H
