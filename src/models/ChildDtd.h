//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_CHILDDTD_H
#define XMLVALIDOR_CHILDDTD_H

#include <iostream>

namespace models {
    enum class Occurrence {
        One,
        MinOne,
        ZeroOrMore,
        ZeroOrOne
    };

    class ChildDtd {
    private:
        std::string name;
        Occurrence occurrence;
    public:
        explicit ChildDtd(std::string name, Occurrence occurrence = Occurrence::One);

        std::string getName();

        Occurrence getOccurrence();
    };
}


#endif //XMLVALIDOR_CHILDDTD_H
