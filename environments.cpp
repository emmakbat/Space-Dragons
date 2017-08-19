#include "environments.h"

namespace spaceDragons {

    Environments::Environments(int nid)
    {
        id = nid;
    }

    std::string Environments::getMessage(){
        return "You find yourself in " + environments[id];
    }
}
