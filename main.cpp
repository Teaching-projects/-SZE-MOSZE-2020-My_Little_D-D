//my first commit test 

#include <iostream>
#include <sstream>
#include <string>

#include "Unit.h"

void printUnits(Unit* UnitA, Unit* UnitB){
    std::cout << UnitA->Unit::getName() << " Hp:" << UnitA->Unit::getHealth() << " Damage: " << UnitA->Unit::getDamage() << std::endl;
    std::cout << UnitB->Unit::getName() << " Hp:" << UnitB->Unit::getHealth() << " Damage: " << UnitB->Unit::getDamage() << std::endl;
}

void fight(Unit* UnitA, Unit* UnitB){
    printUnits(UnitA,UnitB);
    while(UnitA->Unit::getHealth() > 0 && UnitB->Unit::getHealth() > 0){
        std::cout << UnitA->getName() << " -> " << UnitB->getName() << std::endl; 
        UnitB->getAttacked(UnitA->getDamage());
        printUnits(UnitA,UnitB);
        if(UnitB->getHealth()<=0){
            break;
        }
        std::cout << UnitB->getName() << " -> " << UnitA->getName() << std::endl;
        UnitA->getAttacked(UnitB->getDamage());
        printUnits(UnitA,UnitB);
        if(UnitA->getHealth()<=0){
            break;
        }
    }
    if(UnitA->getHealth()<=0){
        std::cout << UnitA->getName() << " died. " << UnitB->getName() << " wins. " << std::endl;
    }
    if(UnitB->getHealth()<=0){
        std::cout << UnitB->getName() << " died. " << UnitA->getName() << " wins. " << std::endl;
    }
}

int main(int argc, char** argv){
    Unit* UnitOne = new Unit(argv[1],argv[2],argv[3]);
    Unit* UnitTwo = new Unit(argv[4],argv[5],argv[6]);

    fight(UnitOne,UnitTwo);
    

    delete UnitOne;
    delete UnitTwo;
    return 0;
} 