#include "Vampire.h"
#include "BattleCard.h"
#include "Card.h"
const int VAMPIRE_COINS = 2;
const int VAMPIRE_FORCE = 10;
const int VAMPIRE_DAMGAE_UPON_LOSS = 10;
Vampire::Vampire()
{
    m_cardName = "Vampire";
    m_coins = VAMPIRE_COINS;
    m_damageUponLoss = VAMPIRE_DAMGAE_UPON_LOSS;
    m_force = VAMPIRE_FORCE;
}

void Vampire::uniqeAction(std::unique_ptr<Player> &player)
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
        player->damage(this->m_damageUponLoss);
        player->unbuff(-1);
    }
}
void Vampire::print(std::ostream &os) const
{
    printCardDetails(os, m_cardName);
    printMonsterDetails(os, m_force, m_damageUponLoss, m_coins);
    printEndOfCardDetails(os);
}
