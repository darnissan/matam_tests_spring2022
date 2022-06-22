#ifndef DRAGON_H_
#define DRAGON_H_
#include "../utilities.h"
#include "BattleCard.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Dragon : public BattleCard
{
protected:
    /**
     * @brief printing function
     *
     * @param os
     */
    virtual void print(std::ostream &os) const override;

private:
    std::string m_cardName;

public:
    /**
     * @brief Construct a new Dragon object
     *
     * @param other
     */
    Dragon(const Dragon &other) = default;
    /**
     * @brief assignment operator
     *
     * @param other
     * @return Dragon&
     */
    Dragon &operator=(const Dragon &other) = default;

    /**
     * @brief applying the unique action
     *
     * @param player
     */
    void uniqeAction(std::unique_ptr<Player> &player) override;
    /**
     * @brief Construct a new Dragon object
     *
     */
    Dragon();
    /**
     * @brief Destroy the Dragon object
     *
     */
    ~Dragon() = default;
};

#endif /* DRAGON_H_ */