#ifndef VAMPIRE_H_
#define VAMPIRE_H_
#include "../utilities.h"
#include "BattleCard.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Vampire : public BattleCard
{
private:
    std::string m_cardName;

public:
    Card *clone() const;
    void uniqeAction(std::unique_ptr<Player> &player) override;
    Vampire();
    ~Vampire(){};
    void print(std::ostream &os) const;
};

#endif /* VAMPIRE_H_ */