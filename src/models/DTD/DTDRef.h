//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_DTDREF_H
#define XMLVALIDOR_DTDREF_H

#include <iostream>
#include <map>
#include "../ElementDtd/ElementDtdRef.h"
#include "../../infrastructures/factories/ElementDtdFactory/ElementDtdFactoryRef.h"
#include "../../infrastructures/factories/ChildDtdFactory/ChildDtdFactoryRef.h"
#include "DTD.h"

namespace models {
    class DTDRef : public DTD {
    private:
        std::string filePath;
        std::map<std::string, ElementDtd *> elements;
    public:
        explicit DTDRef(std::string filePath);

        ~DTDRef() override;

        std::string getFilePath() override;

        std::map<std::string, ElementDtd *> getElementsMap() override;

        ElementDtd *getElementByName(const std::string &name) override;

        void addElement(ElementDtd *element) override;
    };
}

#endif //XMLVALIDOR_DTDREF_H
