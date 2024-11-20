#include "Game.h"

// Constructor
Game::Game()
{
    this->Player1 = new Player(EPlayerType::One, 1, 1);
    this->Player2 = new Player(EPlayerType::Two, 13, 13);
    this->map = new Map(Player1,Player2);
}

// Destructor
Game::~Game() {
    // Perform any necessary cleanup
    map->ResetMap();
    delete map;
    delete Player1;
    delete Player2;
}

// Listener management
void Game::addGameListener(IGameListener* listener) {
    if (listener) {
        listeners.push_back(listener);
    }
}

void Game::removeGameListener(IGameListener* listener) {
    listeners.erase(
        std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
}

IMap* Game::getMap()
{
    return map;
}

bool Game::isOver()
{
    return this->gameIsOver;
}

void Game::SetGameOver()
{
    this->gameIsOver = true;
}

void Game::MovePlayer(EPlayerType playerType, EPlayerMovementType movementDir)
{
    if (playerType == EPlayerType::One)
    {
        map->MovePlayer(Player1, movementDir);
    }
    else
    {
        map->MovePlayer(Player2, movementDir);
    }
}

//// Game-specific methods
//void Game::OnDestroy() {
//    notifyPlayerDestroyed();
//    // Additional logic for destroying game objects
//}
//
//void Game::OnPlaceBomb() {
//    notifyPlayerPlacedBomb();
//    // Additional logic for placing a bomb
//}
//
//void Game::OnPlayerMove(int dx, int dy) {
//    // Example: Update Player1's position
//    if (Player1) {
//        auto pos = Player1->GetPosition();
//        Player1->SetPosition(pos.first + dx, pos.second + dy);
//    }
//    notifyPlayerMoved();
//}
//
//// Helper functions to notify listeners
//void Game::notifyPlayerMoved() {
//    for (auto* listener : listeners) {
//        if (listener) {
//            listener->OnPlayerMoved();
//        }
//    }
//}
//
//void Game::notifyPlayerPlacedBomb() {
//    for (auto* listener : listeners) {
//        if (listener) {
//            listener->OnBombPlaced();
//        }
//    }
//}
//
//void Game::notifyPlayerDestroyed() {
//    for (auto* listener : listeners) {
//        if (listener) {
//            listener->OnPlayerDestroyed();
//        }
//    }
//}
