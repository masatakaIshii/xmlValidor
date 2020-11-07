//
// Created by masat on 02/11/2020.
//

#include "ChildDtdFactory.h"

ChildDtdFactory::ChildDtdFactory() {

}

ChildDtd ChildDtdFactory::createChild(std::string name, std::string occurrence) {
    return ChildDtd(std::move(name), std::move(occurrence));
}
