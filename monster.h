#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <unordered_map>

namespace spaceDragons{

    struct attributes{
        std::string species;
        std::string attack;
        std::string special;
        std::string defense;
        std::string waitText;
    };

    class Monster
    {
    public:
        Monster(int id, int mod);

        //attributes populated from map
        std::string species;
        std::string attack;
        std::string special;
        std::string defense;
        std::string waitText;

        //fight variables
        int hp;
        int attackDamage;
        int specialDamage;
        int defenseSubtraction;
        bool defending;

        //returns: attack, special, defense, or wait
        std::string monsterTurn();

    private:

        //value to select from monsters map
        int id;

        //add to one
        double attackProbability;
        double specialProbability;
        double defenseProbability;
        double waitProbability;

        std::string nmonsters [17] = {"behir", "seawolf", "wereshark", "thork", "deadly pudding", "planetar", "cat lord", "cloaker", "basidirond",
                                   "carnivorous flying squirrel", "the KARNS beaver", "hippocampus", "demagorgon", "literally a five-headed dragon",
                                   "giant space slug", "thought eater",
                                   "space dragon"};
        std::unordered_map<int, attributes> monsters;
        void populateMonsters();
    };
}

#endif // MONSTER_H
