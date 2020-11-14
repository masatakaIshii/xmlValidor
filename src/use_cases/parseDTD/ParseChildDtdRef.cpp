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
    std::vector<std::string> names;
    bool hasOnlyOneName = std::string::npos == name.find('|');
    OccurrenceChildDtd occurrence = this->getOccurrenceByName(name);
    std::string currentName(name);

    if (occurrence != OccurrenceChildDtd::One) {
        currentName = currentName.substr(0, currentName.size() - 1);
    }
    names = StringUtils::split(
            this->removeBeginAndEndParenthesis(currentName),
            "|");
    childDtd = childDtdFactory->createChild(
            names[0],
            occurrence,
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
