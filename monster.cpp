#include "monster.h"
#include "modifiers.h"
#include "attributes.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

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
    }

    void Monster::populateMonsters(){
        std::ifstream readMonsters("C:\\Users\\emmab\\Documents\\Space-Dragons\\monsterVals.csv");
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

            monsters[i] = vals;
            ++i;
        }
    }
    std::string Monster::monsterTurn(){
        return "attack";
    }
}
