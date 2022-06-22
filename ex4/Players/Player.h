#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string>
class Player
{
public:
    /**
     * @brief
     *
     */
    void totalyDead();
    /**
     * @brief Construct a new Player object
     *
     * @param name
     */
    Player(std::string name);
    /**
     * @brief Construct a new Player object
     *
     */
    Player();
    /**
     * @brief increase the player's level
     *
     */
    void levelUp();
    /**
     * @brief Get the Level object
     *
     * @return int
     */
    int getLevel() const;
    /**
     * @brief increase the forcr
     *
     * @param force
     */
    void buff(int force);
    /**
     * @brief deacrese the force of the player
     *
     * @param force
     */
    void unbuff(int force);
    /**
     * @brief increae the hp of the player
     *
     * @param heal
     */
    virtual void heal(int heal);
    /**
     * @brief decrese hp of the player
     *
     * @param damage
     */
    void damage(int damage);
    /**
     * @brief addCoins to the player
     *
     * @param coins
     */
    virtual void addCoins(int coins);
    /**
     * @brief pays coins from player
     *
     * @param pay
     * @return true
     * @return false
     */
    bool pay(int pay);
    virtual int getAttackStrength() const;
    /**
     * @brief returns true if the player knocked out
     *
     * @return true
     * @return false
     */
    bool isKnockedOut() const;
    /**
     * @brief Get the Coins object
     *
     * @return int
     */
    int getCoins() const;
    /**
     * @brief get the hp object
     *
     * @return int
     */
    int getHP() const;
    /**
     * @brief Construct a new Player object
     *
     */
    Player(const Player &) = default;
    /**
     * @brief Destroy the Player object
     *
     */
    ~Player() = default;
    /**
     * @brief Get the Name object
     *
     * @return std::string
     */
    std::string getName() const;
    /**
     * @brief printing operator
     *
     * @param os
     * @param player
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Player &player);
    /**
     * @brief Get the Job object
     *
     * @return std::string
     */
    virtual std::string getJob() const = 0;

protected:
private:
    virtual Player &operator=(const Player &other) = default;
    std::string m_name;
    int m_level;
    int m_force;
    int m_HP;
    int m_coins;
};

#endif // EX4_PLAYER_H
