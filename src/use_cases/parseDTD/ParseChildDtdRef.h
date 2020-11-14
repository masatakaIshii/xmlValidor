//
// Created by masat on 12/11/2020.
//

#ifndef XMLVALIDOR_PARSECHILDDTDREF_H
#define XMLVALIDOR_PARSECHILDDTDREF_H

#include "ParseChildDtd.h"
#include "../../infrastructures/factories/ChildDtdFactory/ChildDtdFactory.h"

using namespace factories;

namespace use_cases {
    class ParseChildDtdRef : public ParseChildDtd {
    private:
        ChildDtdFactory *childDtdFactory;

        OccurrenceChildDtd getOccurrenceByName(std::string name);

        std::string removeBeginAndEndParenthesis(const std::string &name);
    public:
        explicit ParseChildDtdRef(ChildDtdFactory *childDtdFactory);

        ChildDtd *parseChildDtd(const std::string &childContent) override;

        ~ParseChildDtdRef() override;
    };
}

#endif //XMLVALIDOR_PARSECHILDDTDREF_H
