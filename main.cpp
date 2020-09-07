//Nghi Tran
//This is my own work.
#include <string>
using namespace std;
#include <iostream>
#include <iomanip>
#include <ctime>

#include "Game.h"


int main()
{
    srand(time(NULL));
    Game game;
    game.initGame();
    while(game.getPlaying())
    {
        game.mainMenu();
    }
    return 0;
}
