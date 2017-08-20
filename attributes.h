#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <string>

namespace spaceDragons {

    struct attributes{
        std::string species;
        std::string attack;
        std::string special;
        std::string defense;
        std::string waitText;

        attributes():species(""),attack(""),special(""),defense(""),waitText(""){}
    };
}

#endif // ATTRIBUTES_H
