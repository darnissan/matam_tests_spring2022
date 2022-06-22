#ifndef EX4_Rogue_H
#define EX4_Rogue_H
#include "Player.h"

class Rogue : public Player
{
public:
    Rogue(const Rogue &other) = default;
    Rogue &operator=(const Rogue &other) = default;
    Rogue(std::string name)
        : Player(name){};
    ~Rogue() = default;
    void addCoins(int coins) override;
    std::string getJob() const override;
};

#endif // EX4_Rogue_H
