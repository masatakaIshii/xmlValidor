//
// Created by masat on 02/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTDTDFACTORYREF_H
#define XMLVALIDOR_ELEMENTDTDFACTORYREF_H

#include <iostream>
#include "../../../models/ElementDtd/ElementDtd.h"
#include "ElementDtdFactory.h"

using namespace models;

namespace factories {
    class ElementDtdFactoryRef : public ElementDtdFactory {

    public:
        ElementDtdFactoryRef();

        ElementDtd *createElement(std::string name) override;
    };
}

#endif //XMLVALIDOR_ELEMENTDTDFACTORYREF_H
