#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <unordered_map>

struct attributes{
    std::string species;
    std::string attack1;
    std::string attack2;
    std::string defense;
    std::string waitText;
    };
};

class Monster
{
public:
    Monster(int id);

private:

    int id;

    std::string nmonsters [16] = {"behir", "seawolf", "wereshark", "deadly pudding", "planetar", "cat lord", "cloaker", "basidirond",
                               "carnivorous flying squirrel", "the KARNS beaver", "hippocampus", "demagorgon", "literally a five-headed dragon",
                               "giant space slug", "thought eater",
                               "space dragon"};
    std::unordered_map<int, attributes> monsters;
};

#endif // MONSTER_H
