#ifndef PITFALL_H_
#define PITFALL_H_
#include "../utilities.h"
#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Pitfall : public Card {
protected:
    virtual void print(std::ostream& os) const override ;

private:
    std::string m_cardName;

public:
Card* clone() const  ;
    void uniqeAction(std::unique_ptr<Player>& player) override;
    Pitfall() ;
    ~Pitfall() {};
};

#endif /* PITFALL_H_ */