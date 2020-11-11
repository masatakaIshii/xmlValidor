//
// Created by masat on 11/11/2020.
//

#ifndef XMLVALIDOR_CHILDNOTFOUND_H
#define XMLVALIDOR_CHILDNOTFOUND_H

#include <exception>
#include <string>
#include <utility>

class ChildNotFoundException: public std::exception {
public:
    explicit ChildNotFoundException(std::string sentence = "") : sentence(std::move(sentence)){};

    const char* what() const noexcept override {
        return sentence.c_str();
    }
private:
    std::string sentence;
};

#endif //XMLVALIDOR_CHILDNOTFOUND_H
