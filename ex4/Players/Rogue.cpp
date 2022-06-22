#include "Rogue.h"

void Rogue::addCoins(int coins)
{
    coins = coins * 2;
    Player::addCoins(coins);
}

std::string Rogue::getJob() const
{
    return "Rogue";
}