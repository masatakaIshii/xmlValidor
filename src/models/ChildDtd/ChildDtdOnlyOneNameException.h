//
// Created by masat on 13/11/2020.
//

#ifndef XMLVALIDOR_CHILDDTDONLYONENAMEEXCEPTION_H
#define XMLVALIDOR_CHILDDTDONLYONENAMEEXCEPTION_H

#include <exception>

class ChildDtdOnlyOneNameException : public std::exception {
public:
    ChildDtdOnlyOneNameException()= default;

    const char *what() const noexcept override {
        return "This ChildDtd can has only one name";
    }
};

#endif //XMLVALIDOR_CHILDDTDONLYONENAMEEXCEPTION_H
