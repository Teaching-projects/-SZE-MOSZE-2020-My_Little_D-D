#include <iostream>
#include <sstream>
#include <string>

#include "Unit.h"

void printUnits(const Unit& UnitA,const Unit& UnitB) {
    std::cout << UnitA.getName() << " Hp:" << UnitA.getHealth() << " Damage: " << UnitA.getDamage() << std::endl;
    std::cout << UnitB.getName() << " Hp:" << UnitB.getHealth() << " Damage: " << UnitB.getDamage() << std::endl;
}

void printUnit(Unit* Unit){
    std::cout << Unit->getName() << " " << Unit->getHealth() << " " << Unit->getDamage() << std::endl;
}

void fight(Unit& UnitA, Unit& UnitB){
    while(UnitA.getHealth() > 0 && UnitB.getHealth() > 0){
        UnitB.getAttacked(UnitA);
        if(UnitB.getHealth()<=0){
            break;
        }
        UnitA.getAttacked(UnitB);
        if(UnitA.getHealth()<=0){
            break;
        }
    }
    if(UnitA.getHealth()<=0){
        std::cout << UnitB.getName() << " wins. Remaining HP:" << UnitB.getHealth()<< std::endl; 
    }
    if(UnitB.getHealth()<=0){
        std::cout << UnitA.getName() << " wins. Remaining HP:" << UnitA.getHealth()<< std::endl; 
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