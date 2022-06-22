#include "../Mtmchkin.h"

int main()
{
    try
    {
        Mtmchkin game("deck.txt");
        while (!game.isGameOver() && game.getNumberOfRounds() < 100)
        {
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}