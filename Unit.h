#ifndef HEADERFILE_H
#define HEADERFILE_H


#include <string>

class Unit
{
private:
    const std::string Name;
    int Health;
    const int Damage;
public:
    Unit(std::string pName,double pHealth, double pDamage);
    std::string getName() const;
    double getHealth() const;
    double getDamage() const;
    void getAttacked(Unit& unitAttacker);
};

#endif
