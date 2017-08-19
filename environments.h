#ifndef ENVIRONMENTS_H
#define ENVIRONMENTS_H

#include <string>

namespace spaceDragons {

    class Environments
    {
    public:
        Environments(int id);

        std::string getMessage();

    private:
        int id;
        std::string environments [11]= {"the void of space","a desolate moon plain", "the edge of an event horizon", "an asteroid field",
                                     "the astral plane", "the rings of Globitron-5", "an Italian bistro?", "the tail of a comet",
                                     "too close to a star oh god", "the glorious cosmos", "a backwater arm of the Milky Way"};
    };
}

#endif // ENVIRONMENTS_H
