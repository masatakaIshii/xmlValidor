//
// Created by masat on 01/11/2020.
//

#include "ChildDtd.h"

#include <utility>


ChildDtd::ChildDtd(std::string name, std::string occurrence) {
    this->name = std::move(name);
    this->occurrence = std::move(occurrence);
}


std::string ChildDtd::getName() {
    return this->name;
}

std::string ChildDtd::getOccurrence() {
    return this->occurrence;
}
