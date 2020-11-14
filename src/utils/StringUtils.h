//
// Created by masat on 13/11/2020.
//

#ifndef XMLVALIDOR_STRINGUTILS_H
#define XMLVALIDOR_STRINGUTILS_H

#include <iostream>
#include <vector>

namespace utils {
    class StringUtils {
    public:
        static std::vector<std::string> split(const std::string &text, const std::string &delimiter);
    };
}

#endif //XMLVALIDOR_STRINGUTILS_H
