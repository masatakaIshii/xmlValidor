//
// Created by masat on 11/11/2020.
//

#ifndef XMLVALIDOR_IELEMENTDTD_H
#define XMLVALIDOR_IELEMENTDTD_H

#include <iostream>
#include <map>
#include "../ChildDtd/ChildDtd.h"

namespace models {
    class ElementDtd {
    public:
        virtual ~ElementDtd() = default;

        virtual std::string getName() = 0;

        virtual void addChildDtd(ChildDtd *) = 0;

        virtual std::map<std::string, ChildDtd *> getChildren() = 0;

        virtual ChildDtd *getChildByName(std::string) = 0;
    };
}

#endif //XMLVALIDOR_IELEMENTDTD_H
