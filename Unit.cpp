#include "Unit.h"


Unit::Unit(std::string pName,double pHealth, double pDamage) : Name(pName), Damage(pDamage), Health(pHealth){};

std::string Unit::getName() const{
    return Name;
}
double Unit::getHealth() const{
    return Health;
}
double Unit::getDamage() const{
    return Damage;
}

void Unit::getAttacked(const Unit& unitAttacker){
    Health -= unitAttacker.getDamage();
    if(Health < 0){
        Health = 0;
    }
}