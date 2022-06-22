#ifndef CARD_H_
#define CARD_H_
#include "../Players/Player.h"
#include"../utilities.h"
#include <iostream>
#include <stdlib.h>
#include <memory>
#include <string>
class Card {
protected:
    std::string m_cardName;
    friend std::ostream& operator<<(std::ostream& os, const Card& card)
    {
        card.print(os);
        return os;
    }
    virtual void print(std::ostream& os) const = 0;

private:
    // std::unique_ptr<Card> m_currentCardType;

public:
    virtual Card* clone() const =0;
    virtual void uniqeAction(std::unique_ptr<Player>& player) = 0;
    /*
Card(CardType cardType)
{
    switch (cardType)
    {
    case CardType::Barfight1:
        return Barfight();
        break;
    case CardType::Dragon:
        return Dragon();
        break;
        {
            m_cardName = cardName;
            switch ()
            {
            }
        }
        */
    Card();
    virtual ~Card() {};

    // virtual void print(std::ostream &os) const = 0;
};
#endif /* CARD_H_ */