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
    /**
     * @brief Construct a new Vampire object
     *
     * @param other
     */
    Vampire(const Vampire &other) = default;
    /**
     * @brief assignment operator
     *
     * @param other
     * @return Vampire&
     */
    Vampire &operator=(const Vampire &other) = default;
    /**
     * @brief clone operator
     *
     * @return Card*
     */
    Card *clone() const;
    /**
     * @brief applying the unique action
     *
     * @param player
     */
    void uniqeAction(std::unique_ptr<Player> &player) override;
    /**
     * @brief Construct a new Vampire object
     *
     */
    Vampire();
    /**
     * @brief Destroy the Vampire object
     *
     */
    ~Vampire() = default;
    /**
     * @brief printing function
     *
     * @param os
     */
    void print(std::ostream &os) const;
};

#endif /* VAMPIRE_H_ */