#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"

class Wizard : public Player
{
public:
    /**
     * @brief Construct a new Wizard object
     *
     * @param other
     */
    Wizard(const Wizard &other) = default;
    /**
     * @brief assignemet operator
     *
     * @param other
     * @return Wizard&
     */
    Wizard &operator=(const Wizard &other) = default;
    /**
     * @brief Construct a new Wizard object
     *
     * @param name
     */
    Wizard(std::string name)
        : Player(name){};
    /**
     * @brief Destroy the Wizard object
     *
     */
    ~Wizard() = default;
    /**
     * @brief heals the Wizard object
     *
     * @param heal
     */
    void heal(int heal) override;
    /**
     * @brief Get the Job object
     *
     * @return std::string
     */
    std::string getJob() const override;
};

#endif // EX4_WIZARD_H
