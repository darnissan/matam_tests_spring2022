#ifndef BATTLECARD_H_
#define BATTLECARD_H_
#include "../utilities.h"
#include"../Players/Player.h"
#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class BattleCard : public Card {

protected:
    int m_force;
    int m_damageUponLoss;
    int m_coins;
    virtual void print(std::ostream& os) const override;
    virtual void uniqeAction(std::unique_ptr<Player>& player) override = 0;

private:
public:
    BattleCard();
    virtual ~BattleCard() {};
};
#endif /* BATTLECARD_H_ */