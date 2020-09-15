//my first commit test 

#include <iostream>
#include <sstream>
#include <string>

#include "Unit.h"

void const printUnits(Unit UnitA, Unit UnitB) {
    std::cout << UnitA.getName() << " Hp:" << UnitA.getHealth() << " Damage: " << UnitA.getDamage() << std::endl;
    std::cout << UnitB.getName() << " Hp:" << UnitB.getHealth() << " Damage: " << UnitB.getDamage() << std::endl;
}

void fight(Unit& UnitA, Unit& UnitB){
    printUnits(UnitA,UnitB);
    while(UnitA.getHealth() > 0 && UnitB.getHealth() > 0){
        std::cout << UnitA.getName() << " -> " << UnitB.getName() << std::endl; 
        UnitB.getAttacked(UnitA.getDamage());
        printUnits(UnitA,UnitB);
        if(UnitB.getHealth()<=0){
            break;
        }
        std::cout << UnitB.getName() << " -> " << UnitA.getName() << std::endl;
        UnitA.getAttacked(UnitB.getDamage());
        printUnits(UnitA,UnitB);
        if(UnitA.getHealth()<=0){
            break;
        }
    }
    if(UnitA.getHealth()<=0){
        std::cout << UnitA.getName() << " died. " << UnitB.getName() << " wins. " << std::endl;
    }
    if(UnitB.getHealth()<=0){
        std::cout << UnitB.getName() << " died. " << UnitA.getName() << " wins. " << std::endl;
    }
}

int main(int argc, char** argv){
    //Unit* UnitOne = new Unit(argv[1],argv[2],argv[3]);
   // Unit* UnitTwo = new Unit(argv[4],argv[5],argv[6]);

    Unit UnitOne(argv[1],argv[2],argv[3]);
    Unit UnitTwo(argv[4],argv[5],argv[6]);
    fight(UnitOne,UnitTwo);

    return 0;
} 