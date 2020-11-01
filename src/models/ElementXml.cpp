//
// Created by Mikadows on 01/11/2020.
//

#include "ElementXml.h"

ElementXml::ElementXml(std::string name, std::string content) {
    this->name = name;
    this->content = content;
}

ElementXml::~ElementXml() {
    this->name.erase();
    this->content.erase();
    this->childs.clear();
}

/**
 * Return is the ElementXml is valid
 * @return
 */
bool ElementXml::isValid() {
    if( !this->name.empty() &&
        !this->content.empty() ){
        return true;
    }
    return false;
}

/**
 * Add a child
 */
void ElementXml::addChild(const ElementXml& element) {
    this->childs.push_back(element);
}