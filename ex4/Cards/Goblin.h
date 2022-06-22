#ifndef GOBLIN_H_
#define GOBLIN_H_
#include "../utilities.h"
#include "BattleCard.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Goblin : public BattleCard
{
private:
public:
    Goblin(const Goblin &other) = default;
    Goblin &operator=(const Goblin &other) = default;
    Card *clone() const;
    void uniqeAction(std::unique_ptr<Player> &player) override;
    Goblin();
    ~Goblin() = default;
    void print(std::ostream &os) const;
};

#endif /* GOBLIN_H_ */