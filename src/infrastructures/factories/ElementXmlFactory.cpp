//
// Created by Mikadows on 15/11/2020.
//

#include "ElementXmlFactory.h"

ElementXmlFactory::ElementXmlFactory() {

}

ElementXml ElementXmlFactory::createElement(std::string name, std::string content) {
    return ElementXml(name, content);
}