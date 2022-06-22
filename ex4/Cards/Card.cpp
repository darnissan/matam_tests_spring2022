#include "Card.h"
Card::Card()
{
}
std::ostream &operator<<(std::ostream &os, const Card &card)
{
    card.print(os);
    return os;
}