//
// Created by masat on 13/11/2020.
//

#include "StringUtils.h"

using namespace utils;

std::vector<std::string> StringUtils::split(const std::string &text, const std::string &delimiter = "") {
    std::vector<std::string> result;
    std::string currentText(text);
    bool delimiterEmpty = delimiter.empty();
    std::size_t currentPosition = currentText.find(delimiter);

    while (currentPosition != std::string::npos && (currentPosition != 0 || delimiterEmpty)) {
        if (delimiterEmpty) currentPosition++;

        result.push_back(currentText.substr(0, currentPosition));
        currentText = currentText.substr(currentPosition + delimiter.size(), currentText.size());

        if (currentText.size() <= 1) break;

        currentPosition = currentText.find(delimiter);
    }
    result.push_back(currentText);

    return result;
}
