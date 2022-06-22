#include "../Mtmchkin.h"
#include <stdlib.h>
#include <string>
#include <iostream>
int main(int argc, char** argv)
{


    try
    {
	
        Mtmchkin game("tool/deck.txt");
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
    return 0;
}
