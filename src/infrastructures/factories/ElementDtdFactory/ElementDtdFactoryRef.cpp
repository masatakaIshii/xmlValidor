//
// Created by masat on 02/11/2020.
//

#include "ElementDtdFactoryRef.h"
#include "../../../models/ElementDtd/ElementDtdRef.h"

using namespace models;
using namespace factories;

ElementDtdFactoryRef::ElementDtdFactoryRef() = default;

ElementDtd *ElementDtdFactoryRef::createElement(std::string name) {
    return new ElementDtdRef(std::move(name));
}
