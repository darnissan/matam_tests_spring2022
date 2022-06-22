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
    // read input from user and check if number

    // bool intInRange = false;
    // bool isValid=false;
    /*
    do
    {

        std::cin >> m_input;
        std::cout<<"the input is "<< m_input<<std::endl;
        isValid = IsValidInput(m_input);
        intInRange = IsIntInRange();
        if (!isValid||intInRange)
        {
            printInvalidInput();
        }
    } while (intInRange == false ||isValid==false);
    */

    /*
     while (intInRange == false)
     {
         std::getline(std::cin, m_input);
         userChoice = IsValidInput(m_input);
         intInRange = IsIntInRange(userChoice);
         if (!intInRange)
         {
             std::cout<<"this if was checkd with userChoice: "<<userChoice<<" :"<<std::endl;

         }
     }
     */
    while (userChoice == INVALID_USER_CHOICE)
    {
        /*
        do{
        std::getline(std::cin,input);
        if (input.empty())
            printInvalidInput();
        }while (input.size()<0);
        */
        try
        {

            if (!std::getline(std::cin, input) || input.length() != 1 || std::stoi(input) < BUY_NOTHING || std::stoi(input) > FORCE_BOOST_CHOICE)
            {
                //   std::cout<<"current input being tested is : "<<input<<std::endl;
                printInvalidInput();
            }
            else
            {
                //  std::cout<<"current input being tested is : "<<input<<std::endl;
                userChoice = std::stoi(input);
            }
        }
        catch (...)
        {
            // std::cout<<"current input being tested is : "<<input<<std::endl;
            printInvalidInput();
        }
        // std::cout<<"current input being tested is : "<<input<<std::endl;
        // std::cout<<"this is the value of m_input: " << input<<std::endl;

        // userChoice=ReadUserChoiceAndPrintTheRightPrint(input);
    }

    /*std::getline(std::cin, m_input);
    try {
        userChoice = std::stoi(m_input);
    } catch (std::invalid_argument& e) {
        printInvalidInput();
        uniqeAction(player);
    } catch (std::out_of_range& e) {
        printInvalidInput();
        uniqeAction(player);
    }
    */
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
Card *Merchant::clone() const
{
    return new Merchant();
}

int Merchant::IsValidInput(std::string input)
{

    //    bool isValid=true;
    int userChoice;
    try
    {
        userChoice = std::stoi(input);
    }
    catch (std::invalid_argument)
    {

        return -1;
    }

    return userChoice;
}

bool Merchant::IsIntInRange(int num)
{
    if (num < BUY_NOTHING || num > FORCE_BOOST_CHOICE)
    {
        printInvalidInput();
        return false;
    }
    return true;
}

int Merchant::ReadUserChoiceAndPrintTheRightPrint(std::string input)
{
    int userChoice = INVALID_USER_CHOICE;
    try
    {
        userChoice = std::stoi(input);
    }
    catch (std::invalid_argument)
    {

        printInvalidInput();
        return INVALID_USER_CHOICE;
    }
    catch (std::out_of_range)
    {

        printInvalidInput();
        return INVALID_USER_CHOICE;
    }
    if (userChoice < BUY_NOTHING || userChoice > FORCE_BOOST_CHOICE)
    {

        printInvalidInput();
        return INVALID_USER_CHOICE;
    }
    return userChoice;
}