#include "Merchant.h"
#include "../utilities.h"
#include "Card.h"
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
    int userChoice=-1;
    std::string input;
    int playerCoins = player->getCoins();
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player->getName(), playerCoins);
    // read input from user and check if number

   // bool intInRange = false;
    //bool isValid=false;
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
   while (userChoice==-1)
   {
    /*
    do{
    std::getline(std::cin,input);
    if (input.empty())
        printInvalidInput();
    }while (input.size()<0);
    */
    try{
        
        if (!std::getline(std::cin,input) || input.length()!=1|| std::stoi(input)<0 || std::stoi(input)>2)
        {
         //   std::cout<<"current input being tested is : "<<input<<std::endl; 
            printInvalidInput();
        }
        else
        {
          //  std::cout<<"current input being tested is : "<<input<<std::endl; 
            userChoice=std::stoi(input);
        }
    }
    catch (...)
    {
       // std::cout<<"current input being tested is : "<<input<<std::endl; 
        printInvalidInput();
    }
    //std::cout<<"current input being tested is : "<<input<<std::endl;    
    //std::cout<<"this is the value of m_input: " << input<<std::endl;
    
    
    //userChoice=ReadUserChoiceAndPrintTheRightPrint(input);
    
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
    if (userChoice == 1)
    {
        {

            if (playerCoins >= 5)
            {
                player->heal(1);
                player->pay(5);
                printMerchantSummary(std::cout, player->getName(), 1, 5);
            }
            else
            {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player->getName(), 1, 0);
            }
        }
    }
    else if (userChoice == 2)
    {
        if (playerCoins >= 10)
        {
            player->pay(10);
            player->buff(1);
            printMerchantSummary(std::cout, player->getName(), 2, 10);
        }
        else
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player->getName(), 2, 0);
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
         userChoice=std::stoi(input);
    }
    catch (std::invalid_argument)
        {
        
        
        return -1;
        }
    
    
    return userChoice;
}

bool Merchant::IsIntInRange(int num)
{
    if (num < 0 || num > 2)
    {
        printInvalidInput();
        return false;
        
    }
    return true;
}


int Merchant::ReadUserChoiceAndPrintTheRightPrint(std::string input)
{
    int userChoice=-1;
    try
    {
        userChoice=std::stoi(input);
    }
    catch (std::invalid_argument)
    {
        
        printInvalidInput();
        return -1;
    }
    catch  (std::out_of_range)
    {
        
        printInvalidInput();
        return -1;
    }
    if (userChoice < 0 || userChoice > 2)
    {
        
        printInvalidInput();
        return -1;
        
    }
    return userChoice;
}