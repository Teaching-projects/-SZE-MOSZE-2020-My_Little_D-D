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

Unit Unit::parseUnit(std::string fileName){
    std::string tmpString, name = "";
    double health, damage = 0;
    std::string line = "" , searchTerm;
    std::size_t searchResult;
    std::ifstream file(fileName);
    std::stringstream ss;
    if(!file.is_open()){
        Unit outputUnit("ERROR",0,0);
        return outputUnit;
    }
    while (std::getline(file,line))
    {
        searchTerm = "\"name\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
           tmpString = line.substr((searchResult+searchTerm.size()+1));
           tmpString.resize(tmpString.size()-2);
           name = tmpString;
        }

        searchTerm ="\"dmg\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
            tmpString = line.substr(searchResult+searchTerm.size());
            damage = std::stod(tmpString);
        }
        searchTerm = "\"hp\" : ";
        searchResult = line.find(searchTerm);
        if(searchResult != std::string::npos){
            tmpString = line.substr(searchResult+searchTerm.size());
            health = std::stod(tmpString);
        }

    }
    
    file.close();
    Unit outputUnit(name,health,damage);
    return outputUnit;
}
