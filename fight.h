#ifndef FIGHT_H
#define FIGHT_H

#include "monster.h"
#include "player.h"

#include <string>

namespace spaceDragons{
    class Fight
    {
    public:
        Fight(Monster& nmonster, Player& nplayer);
        std::string doFight(std::string turn, std::string action);
        int getHP(){return player.hp;}
        Monster monster{0,0};

    private:
        Player player;

        std::string state;
    };

}
#endif // FIGHT_H
