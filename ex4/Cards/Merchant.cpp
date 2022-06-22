#include "Merchant.h"
#include "../utilities.h"
#include "Card.h"
const int INVALID_USER_CHOICE = -1;
const int HEALTH_POTION_CHOICE = 1;
const int HEALTH_POITION_PRICE = 5;
const int FORCE_BOOST_PRICE = 10;
const int FORCE_BOOST_CHOICE = 2;
const int BUY_NOTHING = 0;
void Merchant::print(std::ostream &os) const
{
    printCardDetails(os, m_cardName);
    printEndOfCardDetails(os);
}

Merchant::Merchant()
{

    m_cardName = "Merchant";
}

void Merchant::uniqeAction(std::unique_ptr<Player> &player)
{
    int userChoice = INVALID_USER_CHOICE;
    std::string input;
    int playerCoins = player->getCoins();
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player->getName(), playerCoins);

    while (userChoice == INVALID_USER_CHOICE)
    {
        try
        {

            if (!std::getline(std::cin, input) || input.length() != 1 || std::stoi(input) < BUY_NOTHING || std::stoi(input) > FORCE_BOOST_CHOICE)
            {

                printInvalidInput();
            }
            else
            {
                userChoice = std::stoi(input);
            }
        }
        catch (...)
        {

            printInvalidInput();
        }
    }

    if (userChoice == 0)
    {
        printMerchantSummary(std::cout, player->getName(), 0, 0);
    }
    if (userChoice == HEALTH_POTION_CHOICE)
    {
        {

            if (playerCoins >= HEALTH_POITION_PRICE)
            {
                player->heal(1);
                player->pay(HEALTH_POITION_PRICE);
                printMerchantSummary(std::cout, player->getName(), HEALTH_POTION_CHOICE, HEALTH_POITION_PRICE);
            }
            else
            {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player->getName(), HEALTH_POTION_CHOICE, 0);
            }
        }
    }
    else if (userChoice == FORCE_BOOST_CHOICE)
    {
        if (playerCoins >= FORCE_BOOST_PRICE)
        {
            player->pay(FORCE_BOOST_PRICE);
            player->buff(1);
            printMerchantSummary(std::cout, player->getName(), FORCE_BOOST_CHOICE, FORCE_BOOST_PRICE);
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player->getName(), FORCE_BOOST_CHOICE, 0);
        }
    }
}
