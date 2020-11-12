//
// Created by masat on 02/11/2020.
//

#include "ChildDtdFactoryRef.h"

#include <utility>

using namespace models;
using namespace factories;

ChildDtdFactoryRef::ChildDtdFactoryRef() = default;


ChildDtd *ChildDtdFactoryRef::createChild(std::string name, OccurrenceChildDtd occurrence) {
    return new ChildDtdRef(std::move(name), occurrence);
}
