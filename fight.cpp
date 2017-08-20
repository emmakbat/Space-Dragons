#include "fight.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

namespace spaceDragons {

    Fight::Fight(Monster& nmonster, Player& nplayer)
    {
        monster = nmonster;
        player = nplayer;
        srand(time(NULL));
    }

    std::string Fight::doFight(std::string turn, std::string action)
    {
        int dmg;
        std::cout << turn << " " << action;
        if(turn == "player"){
            state = action;
            if(state == "attack") {
                if(!monster.defending) {
                    dmg = rand() % 10 + (player.attackDamage - 5);
                    monster.hp -= dmg;
                    return player.attack;
                } else {
                    std::string message = monster.species + " has blocked your attack!!";
                    return message;
                }
            } else if(state == "special") {
                if(!monster.defending) {
                    dmg = rand() % 10 + (player.specialDamage - 10);
                    monster.hp -= dmg;
                    return player.special;
                } else {
                    std::string message = monster.species + " has blocked your attack!!";
                    return message;
                }
            } else if(state == "defend") {
                std::string message = "Player uses " + player.defense + "!!";
                return message;
            } else {
                std::string message = "Player " + player.waitText + ".";
                return message;
            }
            if(monster.hp <= 0) {
                std::string message = monster.species + " has been defeated!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
                return message;
            }
        }
        else{
            state = monster.monsterTurn();
            if(state == "attack") {
                if(!player.defending) {
                    dmg = rand() % 10 + (monster.attackDamage - 5);
                    player.hp -= dmg;
                } else {
                    std::string message = "You have blocked " + monster.species + "'s attack!!";
                    return message;
                }
            } else if(state == "special") {
                if(!player.defending) {
                    dmg = rand() % 10 + (monster.specialDamage - 10);
                    player.hp -= dmg;
                } else {
                    std::string message = "You have blocked " + monster.species + "'s attack!!";
                    return message;
                }
            } else if(state == "defend") {
                std::string message = monster.species + " uses " + monster.defense + "!!";
                return message;
            } else {
                std::string message = monster.species + " " + monster.waitText + ".";
                return message;
            }
            if(player.hp <= 0) {
                std::string message = "Player has been defeated!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
                return message;
            }
        }
        std::string message = "...nothing happened? whoops";
        return message;
    }
}
