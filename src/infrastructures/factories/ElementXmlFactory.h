//
// Created by Mikadows on 15/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTXMLFACTORY_H
#define XMLVALIDOR_ELEMENTXMLFACTORY_H


#include "../../models/ElementXml.h"

class ElementXmlFactory {
public:
    ElementXmlFactory();

    ElementXml createElement(std::string name, std::string content);
};


#endif //XMLVALIDOR_ELEMENTXMLFACTORY_H
