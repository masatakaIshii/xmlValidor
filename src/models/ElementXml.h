//
// Created by Mikadows on 01/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTXML_H
#define XMLVALIDOR_ELEMENTXML_H

#include <iostream>
#include <list>

class ElementXml {
public:
    explicit ElementXml(std::string name, std::string content);
    ~ElementXml();
    bool isValid();
    void addChild(const ElementXml& element);
private:
    std::string name;
    std::list<ElementXml> childs;
    std::string content;
};


#endif //XMLVALIDOR_ELEMENTXML_H
