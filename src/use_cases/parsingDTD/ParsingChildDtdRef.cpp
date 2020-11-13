//
// Created by masat on 12/11/2020.
//

#include "ParsingChildDtdRef.h"

using namespace use_cases;

ParsingChildDtdRef::ParsingChildDtdRef(ChildDtdFactory *childDtdFactory) : childDtdFactory(childDtdFactory) {

}

ChildDtd *use_cases::ParsingChildDtdRef::parseDtd(std::string) {
    return nullptr;
}

ParsingChildDtdRef::~ParsingChildDtdRef() {
    delete childDtdFactory;
}
