#include "Barfight.h"
#include "../Players/Fighter.h"
#include <iostream>
const int hp_damage = 10;
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
    Fighter&     isFighter=dynamic_cast<Fighter&>(*player);
    isFighter.damage(0);
    }
    catch(const std::bad_cast&)
    {
        printBarfightMessage(false);
        player->damage(hp_damage);
        return;
    }
    
    printBarfightMessage(true);
        return;
    /*
    if (player->getJob() == "Fighter")
    {
        printBarfightMessage(true);
        return;
    }
    else
    {
        printBarfightMessage(false);
        player->damage(hp_damage);
    }
    */
}
Card *Barfight::clone() const
{
    return new Barfight();
}