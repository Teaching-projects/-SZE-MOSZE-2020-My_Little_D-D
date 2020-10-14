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

Unit::Unit(const Unit& alpha):
    Name(alpha.getName()),
    Damage(alpha.getDamage()),
    Health(alpha.getHealth())
    {}

Unit Unit::parseUnit(const std::string fileName){
    Parser parse;
    parse.JsonParser(fileName);
    Unit outputUnit (parse.getName(),parse.getHealth(),parse.getDamage());
    return outputUnit;
}
