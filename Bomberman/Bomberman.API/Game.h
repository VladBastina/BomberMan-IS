#pragma once

#include "IGame.h"
#include <vector>
#include "IGameListener.h"
#include "Map.h"
#include "Player.h"


class Game : public IGame {
private:
    IMap* map;
    IPlayer* Player1;
    IPlayer* Player2;

    // List of listeners
    std::vector<IGameListener*> listeners;

public:
    // Constructor and Destructor
    Game();
    ~Game();

    // Listener management
    void addGameListener(IGameListener* listener) override;
    void removeGameListener(IGameListener* listener) override;

    // Game-specific methods
    /*void OnDestroy() override;
    void OnPlaceBomb() override;
    void OnPlayerMove(int dx, int dy) override;*/

private:
    // Helper to notify listeners
    /*void notifyPlayerMoved();
    void notifyPlayerPlacedBomb();
    void notifyPlayerDestroyed();*/
};
