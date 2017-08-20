#ifndef PLAYER_H
#define PLAYER_H

#include <string>

namespace spaceDragons{
    class Player
    {
    public:
        Player();

        //fight variables
        int hp = 100;
        int attackDamage = 10;
        int specialDamage = 20;
        int defenseSubtraction;
        bool defending = false;

        std::string playerTurn();
        std::string attack = "You desperately shoot your blaster";
        std::string special = "You shoot the blaster wildly -- and get a critical hit!";
        std::string defense = "You hide behind your shield";
        std::string waitText = "You sit there. You just...sit there";

    private:
        int xp;
    };
}

#endif // PLAYER_H
