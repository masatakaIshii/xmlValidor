//
// Created by masat on 12/11/2020.
//

#include "ParseChildDtdRef.h"
#include "../../../src/utils/StringUtils.h"

using namespace use_cases;
using namespace utils;

ParseChildDtdRef::ParseChildDtdRef(ChildDtdFactory *childDtdFactory) : childDtdFactory(childDtdFactory) {

}

ChildDtd *use_cases::ParseChildDtdRef::parseChildDtd(const std::string &name) {
    ChildDtd *childDtd;
    bool hasOnlyOneName = std::string::npos == name.find('|');
    std::vector<std::string> names = StringUtils::split(
            this->removeBeginAndEndParenthesis(name),
            "|");

    childDtd = childDtdFactory->createChild(
            names[0],
            this->getOccurrenceByName(name),
            hasOnlyOneName);

    for (int i = 1; i < names.size(); i++) {
        childDtd->addName(names[i]);
    }

    return childDtd;
}

OccurrenceChildDtd ParseChildDtdRef::getOccurrenceByName(std::string name) {
    auto endChar = name.rbegin();
    OccurrenceChildDtd occurrence;
    switch (*endChar) {
        case '+':
            occurrence = OccurrenceChildDtd::MinOne;
            break;
        case '*':
            occurrence = OccurrenceChildDtd::ZeroOrMore;
            break;
        case '?':
            occurrence = OccurrenceChildDtd::ZeroOrOne;
            break;
        default:
            occurrence = OccurrenceChildDtd::One;
    }
    return occurrence;
}

std::string ParseChildDtdRef::removeBeginAndEndParenthesis(const std::string &name) {
    std::string result(name);
    bool isParenthesis = false;
    if (*result.begin() == '(') {
        result = result.substr(1, result.size());
        isParenthesis = true;
    }
    if (isParenthesis) {
        for (auto i = result.size() - 1; i >= 0; i--) {
            if (result[i] == ')') {
                result = result.substr(0, i);
                break;
            }
        }
    }

    return result;
}

ParseChildDtdRef::~ParseChildDtdRef() {
    delete childDtdFactory;
}
