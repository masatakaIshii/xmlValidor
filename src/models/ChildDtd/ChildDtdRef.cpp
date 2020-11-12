//
// Created by masat on 01/11/2020.
//

#include "ChildDtdRef.h"

using namespace models;

ChildDtdRef::ChildDtdRef(std::string name, OccurrenceChildDtd occurrence) : name(std::move(name)), occurrence(occurrence) {

}

std::string ChildDtdRef::getName() {
    return this->name;
}

OccurrenceChildDtd ChildDtdRef::getOccurrence() {
    return this->occurrence;
}

ChildDtdRef::~ChildDtdRef() {

}
