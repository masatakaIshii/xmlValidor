//
// Created by masat on 02/11/2020.
//

#include "ElementFactory.h"

ElementFactory::ElementFactory() {

}

Element ElementFactory::createElement(std::name, ChildDtdFactory &childDtdFactory) {
    return Element(name, childDtdFactory);
}
