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
    this->children.clear();
}

/**
 * Return is the ElementXml is valid
 * @return
 */
bool ElementXml::isValid() {
    if (!this->name.empty() &&
        !this->content.empty()) {
        return true;
    }
    return false;
}

/**
 * Add a child
 */
void ElementXml::addChild(const ElementXml &element) {
    this->children.push_back(element);
}

/**
 * Return every children
 * @return
 */
std::vector<ElementXml> ElementXml::getChildren() {
    return this->children;
}

/**
 * Return the name of the element xml
 * @return
 */
std::string ElementXml::getName() {
    return this->name;
}

/**
 * Return the content of the element xml
 * @return
 */
std::string ElementXml::getContent() {
    return this->content;
}

/**
 * Check if the element are equals
 * @param elementToCompare
 * @return
 */
bool ElementXml::equals(const ElementXml &elementToCompare) {
    if ((this->name == elementToCompare.name) &&
        (this->content == elementToCompare.content)) {
        return true;
    }
    return false;
}
