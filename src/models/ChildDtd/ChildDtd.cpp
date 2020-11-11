//
// Created by masat on 01/11/2020.
//

#include "ChildDtd.h"

using namespace models;

ChildDtd::ChildDtd(std::string name, OccurrenceChildDtd occurrence) : name(std::move(name)), occurrence(occurrence) {

}

std::string ChildDtd::getName() {
    return this->name;
}

OccurrenceChildDtd ChildDtd::getOccurrence() {
    return this->occurrence;
}

ChildDtd::~ChildDtd() = default;


