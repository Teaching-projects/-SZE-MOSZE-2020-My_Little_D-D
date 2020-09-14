#include "Unit.h"


Unit::Unit(std::string pName,std::string pHealth, std::string pDamage)
{
    Name = pName;
    std::stringstream healthValue(pHealth);
    std::stringstream damageValue(pDamage);
    healthValue >> Health;
    damageValue >> Damage;
}
std::string Unit::getName(){
    return Name;
}
int Unit::getHealth(){
    return Health;
}
int Unit::getDamage(){
    return Damage;
}
void Unit::setHealth(int newHealth){
    Health = newHealth;
}
void Unit::getAttacked(int amount){
    Health = Health - amount;
    if(Health < 0){
        Health = 0;
    }
}
Unit::~Unit()
{
}