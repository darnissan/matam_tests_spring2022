#include "Barfight.h"
#include "../Players/Fighter.h"
#include <iostream>
const int hp_damage = 10;
const int NO_DAMAGE = 0;
Barfight::Barfight()
{
    m_cardName = "Barfight";
}
void Barfight::print(std::ostream &os) const
{
    printCardDetails(os, m_cardName);
    printEndOfCardDetails(os);
}
void Barfight::uniqeAction(std::unique_ptr<Player> &player)
{

    try
    {
        Fighter &isFighter = dynamic_cast<Fighter &>(*player);
        isFighter.damage(NO_DAMAGE);
    }
    catch (const std::bad_cast &)
    {
        printBarfightMessage(false);
        player->damage(hp_damage);
        return;
    }

    printBarfightMessage(true);
    return;
}
Card *Barfight::clone() const
{
    return new Barfight();
}