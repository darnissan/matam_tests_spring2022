#ifndef TREASURE_H_
#define TREASURE_H_
#include "../utilities.h"
#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Treasure : public Card
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
     * @brief Construct a new Treasure object
     *
     * @param other
     */
    Treasure(const Treasure &other) = default;
    /**
     * @brief assingment operator
     *
     * @param other
     * @return Treasure&
     */
    Treasure &operator=(const Treasure &other) = default;
    /**
     * @brief clone constructor
     *
     * @return Card*
     */
    Card *clone() const;
    /**
     * @brief unique Action
     *
     * @param player
     */
    void uniqeAction(std::unique_ptr<Player> &player) override;
    /**
     * @brief Construct a new Treasure object
     *
     */
    Treasure();
    /**
     * @brief Destroy the Treasure object
     *
     */
    ~Treasure() = default;
};

#endif /* TREASURE_H_ */