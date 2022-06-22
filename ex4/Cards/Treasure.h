#ifndef TREASURE_H_
#define TREASURE_H_
#include "../utilities.h"
#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Treasure : public Card
{
protected:
    virtual void print(std::ostream &os) const override;

private:
    std::string m_cardName;

public:
    Treasure(const Treasure &other) = default;
    Treasure &operator=(const Treasure &other) = default;
    Card *clone() const;
    void uniqeAction(std::unique_ptr<Player> &player) override;
    Treasure();
    ~Treasure() = default;
};

#endif /* TREASURE_H_ */