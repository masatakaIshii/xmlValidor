//
// Created by Mikadows on 09/11/2020.
//

#include <iostream>
#include "XmlParserService.h"

std::vector<ElementXml> XmlParserService::xmlParser(std::string &fileContent) {
    std::vector<ElementXml> elements = std::vector<ElementXml>();
    std::string elementName;
    std::string elementContent;

    bool flagIn = false;
    bool flagOut = true;
    bool flagSpace = false;

    int i = 0;
    while (fileContent[i] != '\0' && i < fileContent.size()) {

        switch (fileContent[i]) {
            case '<':
                if (flagOut) {
                    flagIn = true;
                    flagOut = false;
                    std::cout << "IN" << std::endl;
                } else {
                    throw nullptr;
                }
                break;
            case '>':
                flagOut = true;
                flagSpace = true;
//                std::cout << "\nOUT" << std::endl;
                break;
            case '?':
                if (fileContent[i - 1] == '<' || fileContent[i + 1] == '>') {
                    elementName.clear();
                    elementContent.clear();
                }
                break;
            case '\n':
                break;
            case ' ':
                flagSpace = true;
                break;
            default:
                if (flagOut) {
                    elementContent += fileContent[i];
                }
                if (flagIn) {
                    elementName += fileContent[i];
                }
                std::cout << elementName << std::endl;
                std::cout << elementContent << std::endl;
                break;
        }

        i++;
    }

    return elements;
}
