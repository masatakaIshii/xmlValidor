//
// Created by masat on 02/11/2020.
//

#include "ChildDtdFactoryRef.h"

#include <utility>

using namespace models;
using namespace factories;

ChildDtdFactoryRef::ChildDtdFactoryRef() = default;

ChildDtd *ChildDtdFactoryRef::createChild(std::string name) {
    return new ChildDtdRef(name);
}

ChildDtd *ChildDtdFactoryRef::createChild(std::string name, OccurrenceChildDtd occurrence) {
    return new ChildDtdRef(name, occurrence);
}

ChildDtd *ChildDtdFactoryRef::createChild(
        std::string name,
        OccurrenceChildDtd occurrence,
        bool hasOnlyOneName) {
    return new ChildDtdRef(name, occurrence, hasOnlyOneName);
}


