#ifndef PITFALL_H_
#define PITFALL_H_
#include "../utilities.h"
#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Pitfall : public Card
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
     * @brief Construct a new Pitfall object
     *
     * @param other
     */
    Pitfall(const Pitfall &other) = default;
    /**
     * @brief assingment operator
     *
     * @param other
     * @return Pitfall&
     */
    Pitfall &operator=(const Pitfall &other) = default;
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
     * @brief Construct a new Pitfall object
     *
     */
    Pitfall();
    /**
     * @brief Destroy the Pitfall object
     *
     */
    ~Pitfall() = default;
};

#endif /* PITFALL_H_ */