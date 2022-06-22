#ifndef BARFIGHT_H_
#define BARFIGHT_H_

#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Barfight : public Card {
protected:
    virtual void print(std::ostream& os) const override;

private:
public:
    Card* clone() const  ;
    void uniqeAction(std::unique_ptr<Player>& player) override;
    Barfight();
    ~Barfight() {};
};

#endif /* BARFIGHT_H_ */