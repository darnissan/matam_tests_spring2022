#ifndef FAIRY_H_
#define FAIRY_H_

#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Fairy : public Card
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
     * @brief Construct a new Fairy object
     *
     * @param other
     */
    Fairy(const Fairy &other) = default;
    /**
     * @brief assignment operator
     *
     * @param other
     * @return Fairy&
     */
    Fairy &operator=(const Fairy &other) = default;
    /**
     * @brief clone constructor
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
     * @brief Construct a new Fairy object
     *
     */
    Fairy();
    /**
     * @brief Destroy the Fairy object
     *
     */
    ~Fairy() = default;
};

#endif /* FAIRY_H_ */