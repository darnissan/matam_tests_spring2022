#include "Treasure.h"
#include "Card.h"
const int treasure_coins = 10;

void Treasure::print(std::ostream &os) const
{
    printCardDetails(os, m_cardName);
    printEndOfCardDetails(os);
}

Treasure::Treasure()
{
    m_cardName = "Treasure";
}

void Treasure::uniqeAction(std::unique_ptr<Player> &player)
{
    printTreasureMessage();
    int coins = treasure_coins;
    player->addCoins(coins);
}
Card *Treasure::clone() const
{
    return new Treasure();
}