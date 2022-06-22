#ifndef DRAGON_H_
#define DRAGON_H_
#include "../utilities.h"
#include "BattleCard.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Dragon : public BattleCard {
protected:
    virtual void print(std::ostream& os) const override
    {
        printCardDetails(os, m_cardName);
        printMonsterDetails(os, m_force, m_damageUponLoss, m_coins, true);
        printEndOfCardDetails(os);
    }

private:
    std::string m_cardName;

public:
     Card* clone() const  ;
    void uniqeAction(std::unique_ptr<Player>& player) override;
    Dragon();
    ~Dragon() {};
};

#endif /* DRAGON_H_ */