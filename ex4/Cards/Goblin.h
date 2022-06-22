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
    /**
     * @brief Construct a new Goblin object
     *
     * @param other
     */
    Goblin(const Goblin &other) = default;
    /**
     * @brief assignment operator
     *
     * @param other
     * @return Goblin&
     */
    Goblin &operator=(const Goblin &other) = default;

    /**
     * @brief applying the unique action
     *
     * @param player
     */
    void uniqeAction(std::unique_ptr<Player> &player) override;
    /**
     * @brief Construct a new Goblin object
     *
     */
    Goblin();
    /**
     * @brief Destroy the Goblin object
     *
     */
    ~Goblin() = default;
    /**
     * @brief printing function
     *
     * @param os
     */
    void print(std::ostream &os) const;
};

#endif /* GOBLIN_H_ */