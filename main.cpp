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
    //printUnits(UnitA,UnitB);
    while(UnitA.getHealth() > 0 && UnitB.getHealth() > 0){
        //std::cout << UnitA.getName() << " -> " << UnitB.getName() << std::endl; 
        UnitB.getAttacked(UnitA);
        //printUnits(UnitA,UnitB);
        if(UnitB.getHealth()<=0){
            break;
        }
        //std::cout << UnitB.getName() << " -> " << UnitA.getName() << std::endl;
        UnitA.getAttacked(UnitB);
        //printUnits(UnitA,UnitB);
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

bool validateUnit(const Unit& unit){
    if(unit.getName() == "ERROR"){
        return false;
    }
    else 
        return true;
}



int main(int argc, char *argv[]){
    Unit UnitOne = Unit::parseUnit(argv[1]);
    Unit UnitTwo = Unit::parseUnit(argv[2]);
    if(!validateUnit(UnitOne) && !validateUnit(UnitTwo)){
        std::cout<< "HIBA!" << std::endl;
        return 1;
    }
    fight(UnitOne,UnitTwo);
    
    
    return 0;
} 