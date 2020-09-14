#ifndef HEADERFILE_H
#define HEADERFILE_H


#include <string>
#include <sstream>

class Unit
{
private:
    std::string Name;
    int Health;
    int Damage;
public:
    Unit(std::string pName,std::string pHealth, std::string pDamage);
    ~Unit();
    std::string getName();
    int getHealth();
    int getDamage();
    void getAttacked(int amount);
    void setHealth(int newHealth);
};

#endif
