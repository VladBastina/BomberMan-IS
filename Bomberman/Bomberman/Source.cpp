#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    Game* game = new Game();

    while (game->running())
    {
        game->update();
        game->render();
    }

    delete game;
    return 0;
}
