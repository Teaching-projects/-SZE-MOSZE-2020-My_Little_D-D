#ifndef HEADERFILE_H
#define HEADERFILE_H


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>
#include <math.h>

class Unit
{
private:
    const std::string Name;
    double Health;
    double Damage;
    double Attackspeed;
    void getAttacked(const Unit* unitAttacker);
public:
    Unit(std::string pName,
            double pHealth,
            double pDamage,
            double Attackspeed);

    std::string getName() const;
    double getHealth() const;
    double getDamage() const;
    double getAttackSpeed() const;
    void attack(const Unit& unitDefender);
    static Unit parseUnit(const std::string fileName);
    Unit(const Unit& alpha);
};

#endif
