#pragma once

#include "IGame.h"
#include "IMap.h"
#include "Player.h"
#include "IGameListener.h"
#include <vector>
#include "Map.h"


class Game : public IGame {
private:
    IMap* map;
    IPlayer* Player1;
    IPlayer* Player2;
    bool gameIsOver;

    // List of listeners
    std::vector<IGameListener*> listeners;

public:
    // Constructor and Destructor
    Game();
    ~Game();

    // Listener management
    void addGameListener(IGameListener* listener) override;
    void removeGameListener(IGameListener* listener) override;

    IMap* getMap() override;

    bool isOver() override;
    void SetGameOver() override;

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
