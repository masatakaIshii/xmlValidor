//
// Created by Mikadows on 09/11/2020.
//

#ifndef XMLVALIDOR_XMLPARSERSERVICE_H
#define XMLVALIDOR_XMLPARSERSERVICE_H


#include <vector>
#include "../../models/ElementXml.h"

class XmlParserService {
public:
    static std::vector<ElementXml> xmlParser(std::string &fileContent);

};


#endif //XMLVALIDOR_XMLPARSERSERVICE_H
