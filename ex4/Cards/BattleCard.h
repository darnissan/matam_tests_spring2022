#ifndef BATTLECARD_H_
#define BATTLECARD_H_
#include "../utilities.h"
#include "../Players/Player.h"
#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class BattleCard : public Card
{

protected:
    int m_force;
    int m_damageUponLoss;
    int m_coins;
    /**
     * @brief prints the card
     *
     * @param os
     */
    virtual void print(std::ostream &os) const override;
    /**
     * @brief applying the unique Action of the Card
     *
     * @param player
     */
    virtual void uniqeAction(std::unique_ptr<Player> &player) override = 0;

private:
public:
    /**
     * @brief Construct a new Battle Card object
     *
     * @param other
     */
    BattleCard(const BattleCard &other) = default;
    /**
     * @brief assignment operator
     *
     * @param other
     * @return BattleCard&
     */
    BattleCard &operator=(const BattleCard &other) = default;
    /**
     * @brief Construct a new Battle Card object
     *
     */
    BattleCard();
    /**
     * @brief Destroy the Battle Card object
     *
     */
    virtual ~BattleCard() = default;
};
#endif /* BATTLECARD_H_ */