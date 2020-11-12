//
// Created by masat on 12/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTDTDNOTFOUNDEXCEPTION_H
#define XMLVALIDOR_ELEMENTDTDNOTFOUNDEXCEPTION_H

#include <exception>
#include <string>
#include <utility>

class ElementDtdNotFoundException : public std::exception {
public:
    explicit ElementDtdNotFoundException(std::string sentence = "") : sentence(std::move(sentence)) {};

    const char *what() const noexcept override {
        return sentence.c_str();
    }

private:
    std::string sentence;
};

#endif //XMLVALIDOR_ELEMENTDTDNOTFOUNDEXCEPTION_H
