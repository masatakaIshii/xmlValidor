//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_CHILDDTD_H
#define XMLVALIDOR_CHILDDTD_H

#include <iostream>

class ChildDtd {
private:
    std::string name;
    std::string occurrence;
public:
    ChildDtd(std::string name, std::string occurrence);
    std::string getName();
    std::string getOccurrence();
};

#endif //XMLVALIDOR_CHILDDTD_H
