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
    int m_currentCardIndex;
    int m_currentPlayerIndex;
    int m_numberOfRounds = 0;
    int m_numberOfPlayers;
    std::vector<std::unique_ptr<Player>> m_WinningPlayers;
    std::vector<std::unique_ptr<Player>> m_LosingPlayers;
    std::vector<std::shared_ptr<Card>> m_deckOfCards;
    std::vector<std::unique_ptr<Player>> m_players;
    std::vector<std::unique_ptr<Player>> m_leadBoard;
    bool isStringInVector(const std::vector<const char *> &vector, const std::string &string);
   bool is_empty(std::ifstream& pFile);
   bool is_blank(std::ifstream& pFile);
    std::unique_ptr<Card> StringToUniquePtrCard(const std::string &string);
    std::unique_ptr<Player> StringToUniquePtrPlayer(const std::string &name, const std::string &m_class);
    void ReadingCardsFromFile(const std::string fileName);
    void ReadingPlayersFromUser();
    bool isValidString(const std::string &string);

public:
    /*
     * C'tor of Mtmchkin class
     *
     * @param filename - a file which contains the cards of the deck.
     * @return
     *      A new instance of Mtmchkin.
     */
    Mtmchkin(const std::string fileName);
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
