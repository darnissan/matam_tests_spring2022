#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"

class Wizard : public Player
{
public:
    Wizard(const Wizard &other) = default;
    Wizard &operator=(const Wizard &other) = default;
    Wizard(std::string name)
        : Player(name){};
    ~Wizard() = default;
    void heal(int heal) override;
    std::string getJob() const override;
};

#endif // EX4_WIZARD_H
