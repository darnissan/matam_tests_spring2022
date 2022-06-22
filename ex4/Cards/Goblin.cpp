#include "Goblin.h"
#include "Card.h"

Goblin::Goblin()
{
    m_cardName = "Goblin";
    m_force = 6;
    m_coins = 2;
    m_damageUponLoss = 10;
}
void Goblin::print(std::ostream &os) const
{
    printCardDetails(os, m_cardName);
    printMonsterDetails(os, m_force, m_damageUponLoss, m_coins);
    printEndOfCardDetails(os);
}

void Goblin::uniqeAction(std::unique_ptr<Player> &player)
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
    }
}

Card *Goblin::clone() const
{
    return new Goblin();
}