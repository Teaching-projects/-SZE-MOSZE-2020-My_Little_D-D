#ifndef HEADERFILE_H
#define HEADERFILE_H


#include <string>
#include <sstream>

class Unit
{
private:
    const std::string Name;
    int Health;
    int Damage;
public:
    Unit(std::string pName,std::string pHealth, std::string pDamage);
    std::string getName() const;
    int getHealth() const;
    int getDamage() const;
    void getAttacked(int amount);
};

#endif
