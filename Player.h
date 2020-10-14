#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <math.h>

class Player {
    private:
        const std::string Name;
        double Health;
        double Damage;
        int level;
        double xpAmount;
    public:
        int getLevel() const;
        double getXpAmount() const;
        void increaseXP(double const amount);
        std::string getName() const;
        double getHealth() const;
        double getDamage() const;
};

#endif