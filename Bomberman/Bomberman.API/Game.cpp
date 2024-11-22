#include "Game.h"

// Constructor
Game::Game()
{
    this->player1 = new Player(EPlayerType::One, 1, 1);
    this->player2 = new Player(EPlayerType::Two, 13, 13);
    this->map = new Map(player1,player2);
}

// Destructor
Game::~Game() {
    // Perform any necessary cleanup
    map->ResetMap();
    delete map;
    delete player1;
    delete player2;
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
        map->MovePlayer(player1, movementDir);
    }
    else
    {
        map->MovePlayer(player2, movementDir);
    }
}

void Game::MovePlayer(IPlayer* player, EPlayerMovementType movementDir)
{
    if (!player->CanMove())
        return;
    std::pair<int, int> playerPosition = player->GetPosition();
    switch (movementDir)
    {
        case EPlayerMovementType::Up:
        {
            ISquare* square = this->map->GetSquare(playerPosition.first - 1, playerPosition.second);
            if (square->HasWall() && !square->HasPlayer())
            {
                player->SetLastMoveTime(std::chrono::steady_clock::now());
                square->SetPlayer(player);
                ISquare* currentSquare = this->map->GetSquare(playerPosition.first, playerPosition.second);
                currentSquare->RemovePlayer();
            }
            break;
        }
        case EPlayerMovementType::Down:
        {
            ISquare* square = this->map->GetSquare(playerPosition.first + 1, playerPosition.second);
            if (square->HasWall() && !square->HasPlayer())
            {
                player->SetLastMoveTime(std::chrono::steady_clock::now());
                square->SetPlayer(player);
                ISquare* currentSquare = this->map->GetSquare(playerPosition.first, playerPosition.second);
                currentSquare->RemovePlayer();
            }
            break;
        }
        case EPlayerMovementType::Left:
        {
            ISquare* square = this->map->GetSquare(playerPosition.first, playerPosition.second - 1);
            if (square->HasWall() && !square->HasPlayer())
            {
                player->SetLastMoveTime(std::chrono::steady_clock::now());
                square->SetPlayer(player);
                ISquare* currentSquare = this->map->GetSquare(playerPosition.first, playerPosition.second);
                currentSquare->RemovePlayer();
            }
            break;
        }
        case EPlayerMovementType::Right:
        {
            ISquare* square = this->map->GetSquare(playerPosition.first, playerPosition.second + 1);
            if (square->HasWall() && !square->HasPlayer())
            {
                player->SetLastMoveTime(std::chrono::steady_clock::now());
                square->SetPlayer(player);
                ISquare* currentSquare = this->map->GetSquare(playerPosition.first, playerPosition.second);
                currentSquare->RemovePlayer();
            }
            break;
        }
    }
}

IPlayer* Game::GetPlayer1()
{
    return player1;
}

IPlayer* Game::GetPlayer2()
{
    return player2;
}

void Game::PlaceBomb(IPlayer* player)
{
    std::pair<int, int> playerPosition = player->GetPosition();
    if (!this->map->HasBombOnSquare(playerPosition) && !player->HasPlacedBomb())
    {
        this->map->PlaceBomb(playerPosition.first, playerPosition.second);
        player->SetPlacedBomb(true);
        
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
