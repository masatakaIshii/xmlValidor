//
// Created by masat on 02/11/2020.
//

#include "ChildDtdFactory.h"

using namespace models;

ChildDtdFactory::ChildDtdFactory() {

}

ChildDtd ChildDtdFactory::createChild(std::string name, Occurrence occurrence) {
    return ChildDtd(std::move(name), std::move(occurrence));
}
