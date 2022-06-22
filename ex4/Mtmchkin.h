#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "Cards/Card.h"
#include "Players/Player.h"
#include "utilities.h"
#include <iostream>
#include <memory>
#include <stdlib.h>
#include <string>
#include <vector>

class Mtmchkin
{
private:
    static const int INVALID_TEAM_SIZE = -1;
    static const int STARTING_RANK = 1;
    static const int MAX_ROUNDS_PER_GAME = 100;
    static const int WINNING_LEVEL = 10;
    static const int FIRST_LINE_INDEX = 1;
    static const int MAX_STRING_LENGTH = 15;
    static const int MAX_TEAM_SIZE = 6;
    static const int MIN_TEAM_SIZE = 2;
    int m_currentCardIndex;
    int m_currentPlayerIndex;
    int m_numberOfRounds = 0;
    int m_numberOfPlayers;
    std::vector<std::unique_ptr<Player>> m_WinningPlayers;
    std::vector<std::unique_ptr<Player>> m_LosingPlayers;
    std::vector<std::shared_ptr<Card>> m_deckOfCards;
    std::vector<std::unique_ptr<Player>> m_players;
    std::vector<std::unique_ptr<Player>> m_leadBoard;
    /**
     * @brief returns if string is in vector
     *
     * @param vector
     * @param string
     * @return true
     * @return false
     */
    bool isStringInVector(const std::vector<const char *> &vector, const std::string &string);
    /**
     * @brief returns if file is empty
     *
     * @param pFile
     * @return true
     * @return false
     */
    bool is_empty(std::ifstream &pFile);
    /**
     * @brief return if file is blank
     *
     * @param pFile
     * @return true
     * @return false
     */
    bool is_blank(std::ifstream &pFile);
    /**
     * @brief returns unique ptr to the correct Card
     *
     * @param string
     * @return std::unique_ptr<Card>
     */
    std::unique_ptr<Card> StringToUniquePtrCard(const std::string &string);
    /**
     * @brief returns the unique ptr for the correct player
     *
     * @param name
     * @param m_class
     * @return std::unique_ptr<Player>
     */
    std::unique_ptr<Player> StringToUniquePtrPlayer(const std::string &name, const std::string &m_class);
    /**
     * @brief reads the cards from the database
     *
     * @param fileName
     */
    void ReadingCardsFromFile(const std::string fileName);
    /**
     * @brief reads the player from the user
     *
     */
    void ReadingPlayersFromUser();
    /**
     * @brief returns if string follows the string rules
     *
     * @param string
     * @return true
     * @return false
     */
    bool isValidString(const std::string &string);

    Mtmchkin(const Mtmchkin &mtmchkin) = delete;
    Mtmchkin &operator=(const Mtmchkin &mtmchkin) = delete;

public:
    /*
     * C'tor of Mtmchkin class
     *
     * @param filename - a file which contains the cards of the deck.
     * @return
     *      A new instance of Mtmchkin.
     */
    explicit Mtmchkin(const std::string &fileName);
    ~Mtmchkin();

    /*
     * Play the next Round of the game - according to the instruction in the exercise document.
     *
     * @return
     *      void
     */
    void playRound();

    /*
     * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
     *
     * @return
     *      void
     */
    void printLeaderBoard() const;

    /*
     *  Checks if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isGameOver() const;

    /*
     *  Returns the number of rounds played.
     *
     *  @return
     *          int - number of rounds played
     */
    int getNumberOfRounds() const;
};

#endif /* MTMCHKIN_H_ */
