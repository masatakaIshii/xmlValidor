//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTDTD_H
#define XMLVALIDOR_ELEMENTDTD_H

#include <iostream>
#include <map>
#include "ChildDtd.h"
#include "../infrastructures/factories/ChildDtdFactory.h"

namespace models {
    class ElementDtd {
    private:
        std::string name;
        std::map<std::string, ChildDtd*> children;
    public:
        explicit ElementDtd(std::string name);
        std::string getName();
        std::map<std::string, ChildDtd*> getChildren;
        void addChildDtd(ChildDtd*);
        ChildDtd* getChildByName(std::string);
    };
}

#endif //XMLVALIDOR_ELEMENTDTD_H
