#include "Game.hpp"

int main()
{
    // Program entry point
    Game game;
    while (!game.GetWindow()->IsDone()){
        // game loop here
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
    }
    return 0;
}