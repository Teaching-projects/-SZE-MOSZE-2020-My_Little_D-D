#include <iostream>
#include <sstream>
#include <string>

#include "Unit.h"

/**
 * @brief Konzolos RPG jatek ket karakter kozott.
 * 
 * Jelenlegi mukodese a programnak ugy tortenik , hogy var ket file nevet mint parancssori argumentum. JSON strukturaban kell leirni benne. 
 * peldaul:
 *
 * {
 *   "name" : "Arthas Menethil",
 *   "hp" : 40000,
 *    "dmg" : 7000
 * }
 
@param UnitA az elso egyseg
@param UnitB a masodik egyseg
 */


void printUnits(const Unit& UnitA,const Unit& UnitB) {
    std::cout << UnitA.getName() << " Hp:" << UnitA.getHealth() << " Damage: " << UnitA.getDamage() << std::endl;
    std::cout << UnitB.getName() << " Hp:" << UnitB.getHealth() << " Damage: " << UnitB.getDamage() << std::endl;
}

/**
* @brief
 * a csata menetelenek kiiratasa, bevitt sebzesek, eletero
*/
void printUnit(Unit* Unit){
    std::cout << Unit->getName() << " " << Unit->getHealth() << " " << Unit->getDamage() << std::endl;
}

/**
*\brief main fuggveny
*\param argc command line argumentomok szama
*\param argv a bemenetkent vart json strukturaju szoveges file
*\return 0 or 1
*\exception fileExist hiba eseten a program 1-el terv vissza
*/
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