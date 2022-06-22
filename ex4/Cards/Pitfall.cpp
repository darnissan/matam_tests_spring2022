#include "Pitfall.h"
#include "Card.h"
#include "../Players/Rogue.h"
const int NO_DAMAGE = 0;
const int hp_damage = 10;
void Pitfall::print(std::ostream &os) const
{
    printCardDetails(os, m_cardName);
    printEndOfCardDetails(os);
}

Pitfall::Pitfall()
{
    m_cardName = "Pitfall";
}
void Pitfall::uniqeAction(std::unique_ptr<Player> &player)
{
    try
    {
        Rogue &isRogue = dynamic_cast<Rogue &>(*player);
        isRogue.damage(NO_DAMAGE);
    }
    catch (const std::bad_cast &)
    {
        printPitfallMessage(false);
        player->damage(hp_damage);
        return;
    }

    printPitfallMessage(true);
    return;
    /*
    if (player->getJob() == "Rogue")
    {
        printPitfallMessage(true);
        return;
    }
    else
    {
        printPitfallMessage(false);
        player->damage(hp_damage);
    }
    */
}
Card *Pitfall::clone() const
{
    return new Pitfall();
}
