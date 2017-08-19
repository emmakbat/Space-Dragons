#ifndef RANDOMNESS_H
#define RANDOMNESS_H

#include <string>
#include <unordered_map>

namespace spaceDragons{

    class Randomness
    {
    public:
        Randomness();

    private:
        std::string encounters [15] = {"acorns", "kale smoothie", "minor healing", "mountain dew", "malkshake", "melkshake", "MILKSHAKE",
                                     "medium healing", "major healing",
                                     "gelatinous cube", "faerie dragon", "quadrone", "planetar", "moon dog", "dolphin"};
        std::string weapons [5] = {"blaster", "laser bow", "laser sword", "crappy spaceship", "ultra super hyper legendary spaceship of doom"};

        std::string modifiers [7] = {"big", "mega", "ultra", "ultra mega", "legendary", "hyperlegendary", "ultra super hyper legendary"};
    };
}

#endif // RANDOMNESS_H
