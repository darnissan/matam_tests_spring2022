#ifndef MERCHANT_H_
#define MERCHANT_H_
#include "../utilities.h"
#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Merchant : public Card
{
protected:
    /**
     * @brief prinitng function
     *
     * @param os
     */
    virtual void print(std::ostream &os) const override;

private:
    std::string m_cardName;

public:
    /**
     * @brief Construct a new Merchant object
     *
     * @param other
     */
    Merchant(const Merchant &other) = default;
    /**
     * @brief assignment operator
     *
     * @param other
     * @return Merchant&
     */
    Merchant &operator=(const Merchant &other) = default;

    /**
     * @brief applying the unique asction
     *
     * @param player
     */
    void uniqeAction(std::unique_ptr<Player> &player) override;
    /**
     * @brief Construct a new Merchant object
     *
     */
    Merchant();
    /**
     * @brief Destroy the Merchant object
     *
     */
    ~Merchant() = default;
};

#endif /* MERCHANT_H_ */