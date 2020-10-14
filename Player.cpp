#include "Player.h"

int Player::getLevel() const{
    return level;
}

double Player::getXpAmount() const{
    return xpAmount;
}

void Player::increaseXP(double const amount){
    xpAmount += amount;
    while(xpAmount> 100){
        level++;
        xpAmount-=100;
        Health = round(Health+(Health*0.1));
        Damage = round(Damage+(Damage*0.1));
    }
}

std::string Player::getName() const{
    return Name;
}
double Player::getHealth() const{
    return Health;
}
double Player::getDamage() const{
    return Damage;
}