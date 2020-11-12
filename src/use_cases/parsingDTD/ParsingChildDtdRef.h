//
// Created by masat on 12/11/2020.
//

#ifndef XMLVALIDOR_PARSINGCHILDDTDREF_H
#define XMLVALIDOR_PARSINGCHILDDTDREF_H

#include "ParsingChildDtd.h"
#include "../../infrastructures/factories/ChildDtdFactory/ChildDtdFactoryRef.h"

namespace use_cases {
    class ParsingChildDtdRef : public ParsingChildDtd {
    private:
        ChildDtdFactory *childDtdFactory;
    public:
        explicit ParsingChildDtdRef(ChildDtdFactory *childDtdFactory);

        ChildDtd *parseDtd(std::string childContent) override;
    };
}

#endif //XMLVALIDOR_PARSINGCHILDDTDREF_H
