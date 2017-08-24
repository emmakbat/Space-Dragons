#include "monster.h"
#include "modifiers.h"
#include "attributes.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace spaceDragons{

    Monster::Monster(int id, int mod)
    {
        modifier = Modifiers::modifiers[mod];
        hp = 100*(mod / 2 +1);
        attackDamage = 10*(mod / 2 +1);
        specialDamage = 20*(mod / 2 +1);

        if(monsters.find(0) == monsters.end()){
            populateMonsters();
        }
        species = monsters[id].species;
        attack = monsters[id].attack;
        special = monsters[id].special;
        defense = monsters[id].defense;
        waitText = monsters[id].waitText;
        image = monsters[id].image;
    }

    void Monster::populateMonsters(){
        std::ifstream readMonsters(".\\resources\\monsterVals.csv");
        int i = 0;
        attributes vals;
        while(readMonsters){
            std::string s;
            if(!getline(readMonsters, s)){break;}
            std::istringstream line(s);
            std::vector<std::string> values;

            while(line){
                std::string s;
                if(!getline(line, s, ',')){break;}
                values.emplace_back(s);
            }
            vals.species = values[0];
            vals.attack = values[1];
            vals.special = values[2];
            vals.defense = values[3];
            vals.waitText = values[4];
            vals.image = values[5];

            monsters[i] = vals;
            ++i;
        }
    }
    std::string Monster::monsterTurn(){
        srand(time(NULL));
        if(hp > 70){
            int move = rand() % 40;
            if(move < 20){
                return "attack";
            }
            else if(move < 30){
                return "defend";
            }
            else if(move < 39){
                return "special";
            }
            else{
                return "wait";
            }
        }
        else{
            int move = rand() % 40;
            if(move < 10){
                return "attack";
            }
            else if(move < 25){
                return "defend";
            }
            else if(move < 39){
                return "special";
            }
            else{
                return "wait";
            }
        }
    }
}
