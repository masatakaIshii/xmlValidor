//
// Created by masat on 01/11/2020.
//

#include "ChildDtdRef.h"
#include "ChildDtdOnlyOneNameException.h"

using namespace models;

ChildDtdRef::ChildDtdRef(const std::string& name, OccurrenceChildDtd occurrence, bool hasOnlyOneName)
        : occurrence(occurrence), hasOnlyOneName(hasOnlyOneName) {
    this->names.push_back(name);
}

std::string ChildDtdRef::getName() {
    return this->names[0];
}

std::vector<std::string> ChildDtdRef::getNames() {
    if (this->hasOnlyOneName) throw ChildDtdOnlyOneNameException();
    return this->names;
}

void ChildDtdRef::addName(std::string name) {
    if (this->hasOnlyOneName) throw ChildDtdOnlyOneNameException();
    this->names.push_back(name);
}

OccurrenceChildDtd ChildDtdRef::getOccurrence() {
    return this->occurrence;
}

void ChildDtdRef::setOccurrence(OccurrenceChildDtd occurrenceChildDtd) {
    this->occurrence = occurrenceChildDtd;
}

ChildDtdRef::~ChildDtdRef() {

}
