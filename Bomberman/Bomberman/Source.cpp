#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    Game game;

    while (game.running())
    {
        game.update();
        game.render();
    }

    return 0;
}
