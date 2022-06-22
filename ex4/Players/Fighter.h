#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H
#include "Player.h"

class Fighter : public Player
{

public:
    Fighter(const Fighter &other) = default;
    Fighter &operator=(const Fighter &other) = default;
    Fighter(std::string name)
        : Player(name){};
    ~Fighter() = default;
    int getAttackStrength() const override;
    std::string getJob() const override;
};
#endif // EX4_FIGHTER_H
