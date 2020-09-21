#ifndef HEADERFILE_H
#define HEADERFILE_H


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>

class Unit
{
private:
    const std::string Name;
    double Health;
    const double Damage;
public:
    Unit(std::string pName,double pHealth, double pDamage);
    std::string getName() const;
    double getHealth() const;
    double getDamage() const;
    void getAttacked(const Unit& unitAttacker);
    static Unit parseUnit(std::string fileName);
    Unit(const Unit& alpha);
};

#endif
