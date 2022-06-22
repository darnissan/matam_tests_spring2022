#ifndef EX4_Rogue_H
#define EX4_Rogue_H
#include "Player.h"

class Rogue : public Player
{
public:
    /**
     * @brief Construct a new Rogue object
     *
     * @param other
     */
    Rogue(const Rogue &other) = default;
    /**
     * @brief assignment operator
     *
     * @param other
     * @return Rogue&
     */
    Rogue &operator=(const Rogue &other) = default;
    /**
     * @brief Construct a new Rogue object
     *
     * @param name
     */
    Rogue(std::string name)
        : Player(name){};
    /**
     * @brief Destroy the Rogue object
     *
     */
    ~Rogue() = default;
    /**
     * @brief add coins to the player
     *
     * @param coins
     */
    void addCoins(int coins) override;
    /**
     * @brief Get the Job object
     *
     * @return std::string
     */
    std::string getJob() const override;
};

#endif // EX4_Rogue_H
