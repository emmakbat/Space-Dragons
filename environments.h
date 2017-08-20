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
        std::string environments [22]= {"the void of space","a desolate moon plain", "the edge of an event horizon", "an asteroid field",
                                     "the astral plane", "the rings of Globitron-5", "an Italian bistro?", "the tail of a comet",
                                     "too close to a star oh god", "the glorious cosmos", "a backwater arm of the Milky Way",
                                       "the all-mighty heavens", "the majesty of our universe", "a suspicious cloud of dust",
                                       "the Horsehead Nebula", "your favorite constellation", "in the midst of a robot laser battle",
                                       "Jack's 24 Hour Space Diner & Bar", "The Restaurant at the End of the Universe",
                                       "God's belly button", "Gallifrey", "the final frontier?!"};
    };
}

#endif // ENVIRONMENTS_H
