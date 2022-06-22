#ifndef BARFIGHT_H_
#define BARFIGHT_H_

#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Barfight : public Card
{
protected:
    virtual void print(std::ostream &os) const override;

private:
public:
    /**
     * @brief Construct a new Barfight object
     *
     * @param other
     */
    Barfight(const Barfight &other) = default;
    /**
     * @brief assignment operator
     *
     * @param other
     * @return Barfight&
     */
    Barfight &operator=(const Barfight &other) = default;

    /**
     * @brief applying the uniqueAction of the Card
     *
     * @param player
     */
    void uniqeAction(std::unique_ptr<Player> &player) override;
    /**
     * @brief Construct a new Barfight object
     *
     */
    Barfight();
    /**
     * @brief Destroy the Barfight object
     *
     */
    ~Barfight() = default;
};

#endif /* BARFIGHT_H_ */