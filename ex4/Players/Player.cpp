#include "Player.h"
#include "../utilities.h"
#include <iostream>

using std::string;

Player::Player(string name)
{
    m_name = name;
    m_HP = 100;
    m_force = 5;
    m_level = 1;
    m_coins = 10;
}

void Player::levelUp()
{
    if (m_level < 10) {
        m_level++;
    }
}
int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int force)
{
    if (force > 0) {
        m_force += force;
    }
}

void Player::unbuff(int force)
{
    m_force += force;
    if (m_force<=0)
    {
        m_force=0;
    }
}

void Player::heal(int heal)
{
    if (heal > 0) {
        if (heal > 0) {
            if (m_HP + heal < 100) {
                m_HP += heal;
            } else {
                m_HP = 100;
            }
        }
    }
}

void Player::damage(int damage)
{
    if (damage > 0) {
        if (m_HP - damage > 0) {
            m_HP -= damage;
        } else {
            m_HP = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
    return (m_HP == 0);
    ;
}

void Player::addCoins(int coins)
{
    if (coins > 0) {
        m_coins += coins;
    }
}

bool Player::pay(int pay)
{
    if (pay >= 0) {
        if (m_coins - pay >= 0) {
            m_coins -= pay;
            return true;
        } else {
            // std::cout << "Not enough coins";
            return false;
        }
    } else {
        return true;
    }
}

int Player::getAttackStrength() const
{
    int attackStrength = m_force + m_level;
    return attackStrength;
}
int Player::getHP() const
{
    return m_HP;
}

int Player::getCoins() const
{
    return m_coins;
}

std::ostream& operator<<(std::ostream& os,const Player& player)
{
    printPlayerDetails(os, player.m_name, player.getJob(),
        player.m_level, player.m_force, player.m_HP, player.m_coins);
    return os;
}

string Player::getName() const
{
    return m_name;
}

void Player::totalyDead()
{
    m_HP = 0;
}
