#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"

class Wizard : public Player {
public:
    Wizard(std::string name)
        : Player(name) {};
    ~Wizard() {};
    void heal(int heal) override;
    std::string getJob() const override;
};

#endif // EX4_WIZARD_H
