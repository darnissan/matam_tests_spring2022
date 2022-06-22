#include "Wizard.h"

void Wizard::heal(int heal)
{
    heal = heal * 2;
    Player::heal(heal);
}

std::string Wizard::getJob() const
{
    return "Wizard";
}