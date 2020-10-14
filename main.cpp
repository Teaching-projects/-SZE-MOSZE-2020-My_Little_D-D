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

int main(int argc, char *argv[]){
    try{
    Unit UnitOne = Unit::parseUnit(argv[1]);
    Unit UnitTwo = Unit::parseUnit(argv[2]);
    UnitOne.attack(UnitTwo);
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
        return 1;
    }
    
    return 0;
} 