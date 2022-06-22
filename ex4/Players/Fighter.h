#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H
#include "Player.h"

class Fighter : public Player
{

public:
    /**
     * @brief Construct a new Fighter object
     *
     * @param other
     */
    Fighter(const Fighter &other) = default;
    /**
     * @brief
     *
     * @param other
     * @return Fighter&
     */
    Fighter &operator=(const Fighter &other) = default;
    /**
     * @brief Construct a new Fighter object
     *
     * @param name
     */
    Fighter(std::string name)
        : Player(name){};
    /**
     * @brief Destroy the Fighter object
     *
     */
    ~Fighter() = default;
    /**
     * @brief Get the Attack Strength object
     *
     * @return int
     */
    int getAttackStrength() const override;
    /**
     * @brief Get the Job object
     *
     * @return std::string
     */
    std::string getJob() const override;
};
#endif // EX4_FIGHTER_H
