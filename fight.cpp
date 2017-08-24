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
        if(monster.hp <= 0) {
            std::string message = monster.species + " has been defeated!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            return message;
        }
        if(player.hp <= 0) {
            std::string message = "Player has been defeated!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            return message;
        }

        int dmg;
        if(turn == "player"){
            state = action;
            player.defending = false;
            if(state == "attack") {
                if(!monster.defending) {
                    dmg = rand() % 10 + (player.attackDamage - 5);
                    monster.hp -= dmg;
                    std::string message = player.attack + std::string("\n You did ") + std::to_string(dmg) + std::string(" damage!");
                    return message;
                } else {
                    std::string message = monster.species + " has blocked your attack!!";
                    return message;
                }
            } else if(state == "special") {
                if(!monster.defending) {
                    dmg = rand() % 10 + (player.specialDamage - 10);
                    monster.hp -= dmg;
                    std::string message = player.special + std::string("\n You did ") + std::to_string(dmg) + std::string(" damage! Wow!");
                    return message;
                } else {
                    std::string message = monster.species + " has blocked your attack!!";
                    return message;
                }
            } else if(state == "defend") {
                std::string message = "Player uses " + player.defense + "!! You avoid all damage!";
                player.defending = true;
                return message;
            } else {
                std::string message = "Player " + player.waitText + ".";
                return message;
            }
        }
        else{
            state = monster.monsterTurn();
            monster.defending = false;
            if(state == "attack") {
                if(!player.defending) {
                    dmg = rand() % 10 + (monster.attackDamage - 5);
                    player.hp -= dmg;
                    std::string message = monster.species + " uses " + monster.attack;
                    return message;
                } else {
                    std::string message = "You have blocked " + monster.species + "'s attack!!";
                    return message;
                }
            } else if(state == "special") {
                if(!player.defending) {
                    dmg = rand() % 10 + (monster.specialDamage - 10);
                    player.hp -= dmg;
                    std::string message = monster.species + " uses " + monster.special;
                    return message;
                } else {
                    std::string message = "You have blocked " + monster.species + "'s attack!!";
                    return message;
                }
            } else if(state == "defend") {
                std::string message = monster.species + " uses " + monster.defense + "!!";
                monster.defending = true;
                return message;
            } else {
                std::string message = monster.species + " " + monster.waitText + ".";
                return message;
            }
        }
        std::string message = "...nothing happened? whoops";
        return message;
    }
}
