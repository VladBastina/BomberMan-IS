#include "GameUI.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    GameUI* game = new GameUI();

    while (game->running())
    {
        game->update();
        game->render();
    }

    delete game;
    return 0;
}
