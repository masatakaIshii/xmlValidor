//
// Created by Mikadows on 09/11/2020.
//

#include <iostream>
#include "XmlParserService.h"

std::vector<ElementXml> XmlParserService::xmlParser(std::string &fileContent) {
    std::vector<ElementXml> elements = std::vector<ElementXml>();
    std::string elementName;
    std::string buffer;


    int i = 0;
    int y = 0;
    while (fileContent[i] != '\0' && i < fileContent.size()) {
//        std::cout << fileContent[i];
//        i++;
        if (fileContent[i] == '<') {
            while (fileContent[y] != ' ') {
                if (fileContent[y] == '?') break;
                std::cout << fileContent[y] << std::endl;
                y++;
            }
            i = y;
        }

        std::cout << fileContent[i];
        i++;
    }

    return elements;
}
