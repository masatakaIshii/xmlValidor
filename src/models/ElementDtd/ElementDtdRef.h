//
// Created by masat on 01/11/2020.
//

#ifndef XMLVALIDOR_ELEMENTDTDREF_H
#define XMLVALIDOR_ELEMENTDTDREF_H

#include <iostream>
#include <map>
#include "../ChildDtd/ChildDtdRef.h"
#include "ElementDtd.h"

namespace models {
    class ElementDtdRef : public ElementDtd {
    private:
        std::string name;
        std::map<std::string, ChildDtd *> children;
    public:
        explicit ElementDtdRef(std::string name);

        ~ElementDtdRef() override;

        std::string getName() override;

        void addChildDtd(ChildDtd *) override;

        std::map<std::string, ChildDtd *> getChildren() override;

        ChildDtd *getChildByName(std::string) override;
    };
}

#endif //XMLVALIDOR_ELEMENTDTDREF_H
