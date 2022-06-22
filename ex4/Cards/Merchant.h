#ifndef MERCHANT_H_
#define MERCHANT_H_
#include "../utilities.h"
#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Merchant : public Card
{
protected:
    virtual void print(std::ostream &os) const override;

private:
    int IsValidInput(std::string input);
    bool IsIntInRange(int num);
    std::string m_cardName;
    int ReadUserChoiceAndPrintTheRightPrint(std::string input);
public:
    Card *clone() const;
    void uniqeAction(std::unique_ptr<Player> &player) override;
    Merchant();
    ~Merchant(){};
};

#endif /* MERCHANT_H_ */