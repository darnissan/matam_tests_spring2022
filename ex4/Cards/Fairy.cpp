#include "Fairy.h"
#include "Card.h"
#include "../Players/Wizard.h"
const int hp_heal = 10;
void Fairy::print(std::ostream &os) const
{
    printCardDetails(os, m_cardName);
    printEndOfCardDetails(os);
}

Fairy::Fairy()
{
    m_cardName = "Fairy";
}

void Fairy::uniqeAction(std::unique_ptr<Player> &player)
{
    try
    {
        Wizard &isWizard = dynamic_cast<Wizard &>(*player);
        isWizard.heal(hp_heal);
    }
    catch (const std::bad_cast &)
    {
        printFairyMessage(false);

        return;
    }

    printFairyMessage(true);
    return;
    /*
    if (Player->getJob() == "Wizard")
    {
        printFairyMessage(true);
        Player->heal(hp_heal);
    }
    else
    {
        printFairyMessage(false);
        return;
    }
    */
}
Card *Fairy::clone() const
{
    return new Fairy();
}