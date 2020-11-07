//
// Created by Mikadows on 01/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTXML_H
#define XMLVALIDOR_ELEMENTXML_H

#include <iostream>
#include <list>
#include <vector>

class ElementXml {
public:
    explicit ElementXml(std::string name, std::string content);

    ~ElementXml();

    bool isValid();

    void addChild(const ElementXml &element);

    std::string getName();

    std::string getContent();

    std::vector<ElementXml> getChildren();

    bool equals(const ElementXml &elementToCompare);

private:
    std::vector<ElementXml> children;
    std::string name;
    std::string content;

};


#endif //XMLVALIDOR_ELEMENTXML_H
