#include "Dragon.h"
#include "BattleCard.h"
#include "Card.h"
#include <climits>
const int DRAGON_FORCE = 25;
const int DRAGON_COINS = 1000;
Dragon::Dragon()
{

    m_cardName = "Dragon";
    m_force = DRAGON_FORCE;
    m_coins = DRAGON_COINS;
    m_damageUponLoss = INT_MAX;
}
void Dragon::uniqeAction(std::unique_ptr<Player> &player)
{
    if (player->getAttackStrength() >= this->m_force)
    {
        player->levelUp();
        player->addCoins(this->m_coins);
        printWinBattle(player->getName(), this->m_cardName);
    }

    else
    {
        printLossBattle(player->getName(), this->m_cardName);
        player->totalyDead();
    }
}
Card *Dragon::clone() const
{
    return new Dragon();
}
void Dragon::print(std::ostream &os) const
{
    printCardDetails(os, m_cardName);
    printMonsterDetails(os, m_force, m_damageUponLoss, m_coins, true);
    printEndOfCardDetails(os);
}
