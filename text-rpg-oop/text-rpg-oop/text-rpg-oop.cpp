#include <iostream>
#include "Game.h"
using namespace std;

// Text RPG - OOP

int main()
{
    srand((unsigned int)time(nullptr));
    Game game;
    game.Init();

    while (true)
        game.Update();

    return 0;
}