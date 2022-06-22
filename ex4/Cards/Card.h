#ifndef CARD_H_
#define CARD_H_
#include "../Players/Player.h"
#include "../utilities.h"
#include <iostream>
#include <stdlib.h>
#include <memory>
#include <string>
class Card
{
protected:
    std::string m_cardName;
    /**
     * @brief printing operator
     *
     * @param os
     * @param card
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Card &card);

    /**
     * @brief printing function
     *
     * @param os
     */
    virtual void print(std::ostream &os) const = 0;

private:
public:
    /**
     * @brief Construct a new Card object
     *
     * @param other
     */
    Card(const Card &other) = default;
    /**
     * @brief assignment operator
     *
     * @param other
     * @return Card&
     */
    Card &operator=(const Card &other) = default;

    /**
     * @brief applying the unique action
     *
     * @param player
     */
    virtual void uniqeAction(std::unique_ptr<Player> &player) = 0;
    /**
     * @brief Construct a new Card object
     *
     */
    Card();
    /**
     * @brief Destroy the Card object
     *
     */
    virtual ~Card() = default;
};
#endif /* CARD_H_ */