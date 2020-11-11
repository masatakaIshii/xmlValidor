//
// Created by masat on 02/11/2020.
//

#include "ElementDtdFactory.h"

#include <utility>

using namespace models;

ElementDtdFactory::ElementDtdFactory() = default;

ElementDtd ElementDtdFactory::createElement(std::string name) {
    return ElementDtd(std::move(name));
}
