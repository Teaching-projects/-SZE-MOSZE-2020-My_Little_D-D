#include "Unit.h"


Unit::Unit(std::string pName,std::string pHealth, std::string pDamage) : Name(pName)
{
    std::stringstream healthValue(pHealth);
    std::stringstream damageValue(pDamage);
    healthValue >> Health;
    damageValue >> Damage;
}
std::string Unit::getName() const{
    return Name;
}
int Unit::getHealth() const{
    return Health;
}
int Unit::getDamage() const{
    return Damage;
}

void Unit::getAttacked(int amount){
    Health -= amount;
    if(Health < 0){
        Health = 0;
    }
}