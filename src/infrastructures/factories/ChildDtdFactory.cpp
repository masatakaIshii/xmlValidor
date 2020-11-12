//
// Created by masat on 02/11/2020.
//

#include "ChildDtdFactory.h"

using namespace models;

ChildDtdFactory::ChildDtdFactory() {

}

ChildDtdRef ChildDtdFactory::createChild(std::string name, OccurrenceChildDtd occurrence) {
    return ChildDtdRef(std::move(name), std::move(occurrence));
}
