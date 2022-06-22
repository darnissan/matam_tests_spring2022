#include "BattleCard.h"
BattleCard::BattleCard(){}
void BattleCard::print(std::ostream& os) const
{
    printCardDetails(os, m_cardName);
    printMonsterDetails(os, m_force, m_damageUponLoss, m_coins);
    printEndOfCardDetails(os);
}
