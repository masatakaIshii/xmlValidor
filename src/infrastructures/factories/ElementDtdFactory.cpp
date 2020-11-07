//
// Created by masat on 02/11/2020.
//

#include "ElementDtdFactory.h"

ElementDtdFactory::ElementDtdFactory() {

}

ElementDtd ElementDtdFactory::createElement(std::string name, ChildDtdFactory &childDtdFactory) {
    return ElementDtd(name, childDtdFactory);
}
