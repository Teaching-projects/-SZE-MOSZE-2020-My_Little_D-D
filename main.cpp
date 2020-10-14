#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

#include "Unit.h"

void printUnits(const Unit& UnitA,const Unit& UnitB) {
    std::cout << UnitA.getName() << " Hp:" << UnitA.getHealth() << " Damage: " << UnitA.getDamage() << std::endl;
    std::cout << UnitB.getName() << " Hp:" << UnitB.getHealth() << " Damage: " << UnitB.getDamage() << std::endl;
}

void printUnit(Unit* Unit){
    std::cout << Unit->getName() << " " << Unit->getHealth() << " " << Unit->getDamage() << std::endl;
}

void fight(Unit& UnitAttacker, Unit& UnitDefender){
    double fightDuration = 0.00;
    //Initial attacks
    UnitDefender.getAttacked(UnitAttacker);
    UnitAttacker.getAttacked(UnitDefender);
    //Timed fight sequence
    while(UnitAttacker.getHealth() > 0 && UnitDefender.getHealth() > 0){
        if(fmod(fightDuration,UnitAttacker.getAttackSpeed())<0.01){
            UnitDefender.getAttacked(UnitAttacker);
            if(UnitDefender.getHealth()<=0){
                break;
            }
            fightDuration += 0.01;
            continue;
        }
        if(fmod(fightDuration,UnitDefender.getAttackSpeed())<0.01){
            UnitAttacker.getAttacked(UnitDefender);
            if(UnitAttacker.getHealth()<=0){
                break;
            }
            fightDuration += 0.01;
            continue;
        }
        fightDuration += 0.01;
    }
    if(UnitAttacker.getHealth()<=0){
        std::cout << UnitDefender.getName() << " wins. Remaining HP:" << UnitDefender.getHealth()<< std::endl; 
    }
    if(UnitDefender.getHealth()<=0){
        std::cout << UnitAttacker.getName() << " wins. Remaining HP:" << UnitAttacker.getHealth()<< std::endl; 
    }
}

int main(int argc, char *argv[]){
    try{
    Unit UnitOne = Unit::parseUnit(argv[1]);
    Unit UnitTwo = Unit::parseUnit(argv[2]);
    fight(UnitOne,UnitTwo);
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
        return 1;
    }
    
    return 0;
} 