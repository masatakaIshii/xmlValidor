//
// Created by masat on 02/11/2020.
//

#include "ChildDtdFactory.h"

#include <utility>

using namespace models;

ChildDtdFactory::ChildDtdFactory() = default;


ChildDtd *ChildDtdFactory::createChild(std::string name, OccurrenceChildDtd occurrence) {
    return new ChildDtdRef(std::move(name), occurrence);
}
