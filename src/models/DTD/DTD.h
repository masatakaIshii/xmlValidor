//
// Created by masat on 12/11/2020.
//

#ifndef XMLVALIDOR_DTD_H
#define XMLVALIDOR_DTD_H

#include <string>
#include <map>
#include "../ElementDtd/ElementDtd.h"

namespace models {
    class DTD {
    public:
        virtual ~DTD() = default;

        virtual std::string getFilePath() = 0;

        virtual std::map<std::string, ElementDtd *> getElementsMap() = 0;

        virtual ElementDtd *getElementByName(const std::string &name) = 0;

        virtual void addElement(ElementDtd *element) = 0;
    };
}

#endif //XMLVALIDOR_DTD_H
