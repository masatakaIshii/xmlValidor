//
// Created by masat on 01/11/2020.
//

#include "ChildDtd.h"

#include <utility>

using namespace models;

ChildDtd::ChildDtd(std::string name, Occurrence occurrence) : name(std::move(name)), occurrence(occurrence) {

}

std::string ChildDtd::getName() {
    return this->name;
}

Occurrence ChildDtd::getOccurrence() {
    return this->occurrence;
}


