#include "Mtmchkin.h"
#include "Cards/Barfight.h"
#include "Cards/Card.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Players/Fighter.h"
#include "Players/Player.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "utilities.h"
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
Mtmchkin::Mtmchkin(const std::string fileName)
{

    printStartGameMessage();
    // std::map<char *, std::unique_ptr<Card>> mapStringToCard = {"Barfight ", std::unique_ptr<Barfight>{new Barfight()}};

    // CardType *currentCardType;
    ReadingCardsFromFile(fileName);
    m_currentCardIndex = 0;
    ReadingPlayersFromUser();
    m_currentPlayerIndex = 0;
}

bool Mtmchkin::isStringInVector(const std::vector<const char *> &vector, const std::string &string)
{
    for (int i = 0; i < (int)vector.size(); i++)
    {
        if (vector[i] == string)
        {

            return true;
        }
    }
    return false;
}
/*
std::unique_ptr<Card> Mtmchkin::StringToUniquePtrCard(const std::string& string)
{
    if (string == "Barfight")
        return std::unique_ptr<Card> { new Barfight() };
    else if (string == "Dragon")
        return std::unique_ptr<BattleCard> { new Dragon() };
    else if (string == "Fairy")
        return std::unique_ptr<Card> { new Fairy() };
    else if (string == "Goblin")
        return std::unique_ptr<Card> { new Goblin() };
    else if (string == "Pitfall")
        return std::uniq3ue_ptr<Card> { new Pitfall() };
    else if (string == "Treasure")
        return std::unique_ptr<Card> { new Treasure() };
    else if (string == "Vampire")
        return std::unique_ptr<Card> { new Vampire() };
    else
        return nullptr;
}
*/
/*
std::unique_ptr<Card> Mtmchkin::StringToUniquePtrCard(const std::string &string)
{
    Barfight *barfight = new Barfight();
    Dragon *dragon = new Dragon();
    Fairy *fairy = new Fairy();
    Goblin *goblin = new Goblin();
    Pitfall *pitfall = new Pitfall();
    Treasure *treasure = new Treasure();
    Vampire *vampire = new Vampire();
    std::map<std::string, Card *> mapStringToCard = {{"Barfight", barfight->clone()}, {"Dragon", dragon->clone()}, {"Fairy", fairy->clone()}, {"Goblin", goblin->clone()}, {"Pitfall", pitfall->clone()}, {"Treasure", treasure->clone()}, {"Vampire", vampire->clone()}};
    return std::unique_ptr<Card>{mapStringToCard[string]};
}
*/
Mtmchkin::~Mtmchkin()
{
    m_players.clear();
    m_WinningPlayers.clear();
    m_LosingPlayers.clear();
    m_deckOfCards.clear();
    m_leadBoard.clear();
}
void Mtmchkin::ReadingCardsFromFile(const std::string fileName)
{

    std::ifstream file(fileName);
    try
    {
        if (!file.is_open())
        {
            throw DeckFileNotFound("Deck File Error: File not found");
        }
        if (is_empty(file) || is_blank(file))
        {
            throw DeckFileInvalidSize("Deck File Error: Deck size is invalid");
        }
    }
    catch (...)
    {
        // mapStringToCard.clear();

        throw;
    }
    int lineNumber = FIRST_LINE_INDEX;
    std::shared_ptr<Card> currentCard;

    static std::map<std::string, const std::shared_ptr<Card>> mapStringToCard = {{"Dragon", std::shared_ptr<Card>(new Dragon())}, {"Fairy", std::shared_ptr<Card>(new Fairy())}, {"Goblin", std::shared_ptr<Card>(new Goblin())}, {"Pitfall", std::shared_ptr<Card>(new Pitfall())}, {"Treasure", std::shared_ptr<Card>(new Treasure())}, {"Vampire", std::shared_ptr<Card>(new Vampire())}, {"Barfight", std::shared_ptr<Card>(new Barfight())}, {"Merchant", std::shared_ptr<Card>(new Merchant())}};

    const std::vector<const char *> CardTypes = {"Barfight", "Dragon", "Fairy", "Goblin", "Pitfall", "Treasure", "Vampire", "Merchant"};
    while (!file.eof())
    {
        std::string line;
        std::getline(file, line);

        if (!isStringInVector(CardTypes, line))
        {
            throw DeckFileFormatError("Deck File Error: File format error in line ", std::to_string(lineNumber));
        }
        else
        {
            // std::unique_ptr<Card> currentCard = Card::Card(cardTypeMap[line]);
            // m_deckOfCards->insert(m_deckOfCards->end(), StringToUniquePtrCard(line));
            currentCard = mapStringToCard.at(line);
            m_deckOfCards.push_back(currentCard);
            lineNumber++;
        }
    }
    if (m_deckOfCards.size() < 5)
    {
        throw DeckFileInvalidSize("Deck File Error: Deck size is invalid");
    }
}
void Mtmchkin::ReadingPlayersFromUser()
{
    const std::vector<const char *> PlayerTypes = {"Wizard", "Rogue", "Fighter"};
    std::string userInput;

    bool validTeamSize = false;

    while (validTeamSize == false)
    {
        printEnterTeamSizeMessage();
        std::getline(std::cin, userInput);
        // std::cout<<"current input been tested is :"<<userInput<<std::endl;
        try
        {
            m_numberOfPlayers = std::stoi(userInput);
            // std::cout<<"this prints from the if"<<std::endl;
            // printInvalidTeamSize();
            // printEnterTeamSizeMessage();
        }
        catch (std::invalid_argument const &ex)
        {
            validTeamSize = false;
            // std::cout<<"this prints from the catch"<<std::endl;
            // printInvalidTeamSize();
            // printEnterTeamSizeMessage();
            m_numberOfPlayers=INVALID_TEAM_SIZE;;
        }
        catch (std::out_of_range)
        {
            m_numberOfPlayers=INVALID_TEAM_SIZE;
            validTeamSize = false;
        }

        if (m_numberOfPlayers >= MIN_TEAM_SIZE && m_numberOfPlayers <= MAX_TEAM_SIZE)
        {
            validTeamSize = true;
        }
        else
        {
            printInvalidTeamSize();
        }
    }
    bool validPlayerName = false, validClassName = false;
    std::string userClassInput;
    for (int i = 0; i < m_numberOfPlayers; i++)
    {
        validPlayerName = false, validClassName = false;
        printInsertPlayerMessage();
        std::cin >> userInput;
        std::cin >> userClassInput;
        while (validPlayerName == false || validClassName == false)
        {
            if (isValidString(userInput) == false)
            {
                printInvalidName();
                std::cin >> userInput;
                std::cin >> userClassInput;
            }
            else if (isValidString(userClassInput) == false || isStringInVector(PlayerTypes, userClassInput) == false)
            {
                printInvalidClass();
                std::cin >> userInput;
                std::cin >> userClassInput;
            }
            else
            {

                validPlayerName = true;
                validClassName = true;
            }
        }
        m_players.insert(m_players.end(), StringToUniquePtrPlayer(userInput, userClassInput));
    }
    std::getline(std::cin, userInput); // clearing whitespaces
}

std::unique_ptr<Player> Mtmchkin::StringToUniquePtrPlayer(const std::string &name, const std::string &m_class)
{
    if (m_class == "Fighter")
        return std::unique_ptr<Player>{new Fighter(name)};
    else if (m_class == "Wizard")
        return std::unique_ptr<Player>{new Wizard(name)};
    else if (m_class == "Rogue")
        return std::unique_ptr<Player>{new Rogue(name)};
    else
        return nullptr;
}

bool Mtmchkin::isValidString(const std::string &string)
{
    if (string.length() > MAX_STRING_LENGTH)
    {
        return false;
    }

    for (int i = 0; i < (int)string.length(); i++)
    {
        if (!isalpha(string[i]))
        {
            return false;
        }
    }
    return true;
}
void Mtmchkin::playRound()
{

    m_numberOfRounds++;
    printRoundStartMessage(m_numberOfRounds);
    if (m_currentCardIndex >= int(m_deckOfCards.size()))
    {
        m_currentCardIndex = 0;
    }
    if (m_currentPlayerIndex >= int(m_players.size()))
    {
        m_currentPlayerIndex = 0;
    }
    while (m_currentPlayerIndex < int(m_players.size()))
    {
        printTurnStartMessage(m_players[m_currentPlayerIndex]->getName());
        m_deckOfCards.at(0)->uniqeAction(m_players.at(m_currentPlayerIndex));
        //   std::cout << *m_deckOfCards.at(0) << std::endl;
        if (m_players.at(m_currentPlayerIndex)->getLevel() >= WINNING_LEVEL)
        {

            m_WinningPlayers.insert(m_WinningPlayers.end(), std::make_move_iterator(m_players.begin() + m_currentPlayerIndex), std::make_move_iterator(m_players.begin() + (m_currentPlayerIndex + 1)));
            m_players.erase(m_players.begin() + m_currentPlayerIndex);
            // m_currentPlayerIndex--;
        }
        else if (m_players.at(m_currentPlayerIndex)->isKnockedOut())
        {

            m_LosingPlayers.insert(m_LosingPlayers.end(), std::make_move_iterator(m_players.begin() + m_currentPlayerIndex), std::make_move_iterator(m_players.begin() + (m_currentPlayerIndex + 1)));
            m_players.erase(m_players.begin() + m_currentPlayerIndex);
            // m_currentPlayerIndex--;
        }

        else
        {
            m_currentPlayerIndex++;
        }
        std::rotate(m_deckOfCards.begin(), m_deckOfCards.begin() + 1, m_deckOfCards.end());
    }
    if (m_players.size() == 0)

    {
        printGameEndMessage();
    }
}

bool Mtmchkin::isGameOver() const
{
    if (int(m_players.size()) <= 0 || m_numberOfRounds >= MAX_ROUNDS_PER_GAME)
    {

        return true;
    }
    return false;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_numberOfRounds;
}

void Mtmchkin::printLeaderBoard() const
{
    int currentRank = STARTING_RANK;
    printLeaderBoardStartMessage();
    for (int i = 0; i < (int)m_WinningPlayers.size(); i++)
    {
        printPlayerLeaderBoard(currentRank, *m_WinningPlayers.at(i));
        currentRank++;
    }
    for (int i = 0; i < (int)m_players.size(); i++)
    {
        printPlayerLeaderBoard(currentRank, *m_players.at(i));
        currentRank++;
    }
    for (int i = (int)m_LosingPlayers.size() - 1; i >= 0; i--)
    {
        printPlayerLeaderBoard(currentRank, *m_LosingPlayers.at(i));
        currentRank++;
    }
}

bool Mtmchkin::is_empty(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

bool Mtmchkin::is_blank(std::ifstream &pFile)
{

    pFile.seekg(0, std::ios::end); // points to the end of file
    int length = pFile.tellg();
    if (length == 0)
        return true;
    pFile.clear();
    pFile.seekg(0);
    return false;
}