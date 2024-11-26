#include "Game.h"

// Constructor
Game::Game() : gameIsOver(false)
{
    this->player1 = new Player(EPlayerType::One, 1, 1);
    this->player2 = new Player(EPlayerType::Two, 13, 13);
    this->map = new Map(player1,player2);
}

Game::~Game() {
    map->ResetMap();
    delete map;
    delete player1;
    delete player2;
}

bool Game::addGameListener(IGameListener* listener) 
{
    listeners.push_back(listener);
    return true;
}

bool Game::removeGameListener(IGameListener* listener) 
{
    for (auto it = listeners.begin(); it != listeners.end(); ++it)
    {
        if (*it == listener)
        {
            listeners.erase(it);
            return true;
        }
    }

    return false;
}

IMap* Game::getMap()
{
    return map;
}

bool Game::isOver()
{
    return this->gameIsOver;
}

IPlayer* Game::GetPlayer1()
{
    return player1;
}

IPlayer* Game::GetPlayer2()
{
    return player2;
}

void Game::SetGameOver()
{
    this->gameIsOver = true;
    // Notify listeners about game over (if needed)
    for (auto* listener : listeners) {
        listener->OnPlayerDestroyed();
    }
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

    std::pair<int, int> oldPosition = player->GetPosition();
    std::pair<int, int> newPosition = oldPosition;

    switch (movementDir)
    {
    case EPlayerMovementType::Up:
        newPosition.first -= 1;
        break;
    case EPlayerMovementType::Down:
        newPosition.first += 1;
        break;
    case EPlayerMovementType::Left:
        newPosition.second -= 1;
        break;
    case EPlayerMovementType::Right:
        newPosition.second += 1;
        break;
    }

    ISquare* targetSquare = this->map->GetSquare(newPosition.first, newPosition.second);
    if (targetSquare && targetSquare->HasWall() && !targetSquare->HasPlayer())
    {
        player->SetLastMoveTime(std::chrono::steady_clock::now());
        targetSquare->SetPlayer(player);

        ISquare* currentSquare = this->map->GetSquare(oldPosition.first, oldPosition.second);
        currentSquare->RemovePlayer();

        // Notify listeners about player movement
        for (auto* listener : listeners) {
            listener->OnPlayerMoved(newPosition.first, newPosition.second);
        }
    }
}

void Game::PlaceBomb(IPlayer* player)
{
    std::pair<int, int> playerPosition = player->GetPosition();
    if (!this->map->HasBombOnSquare(playerPosition) && !player->HasPlacedBomb())
    {
        this->map->PlaceBomb(playerPosition.first, playerPosition.second);
        player->SetPlacedBomb(true);
        activeBombs.push_back(std::make_tuple(playerPosition.first, playerPosition.second,player ));

        // Notify listeners about bomb placement
        for (auto* listener : listeners) {
            listener->OnPlayerPlacedBomb(playerPosition.first, playerPosition.second);
        }
    }
}

void Game::HandleExplosion(float elapsedTime)
{
    for (auto bomb=activeBombs.begin(); bomb!=activeBombs.end();)
    {
        ISquare* square = map->GetSquare(std::get<0>((*bomb)), std::get<1>((*bomb)));
        if (square && square->GetBomb())
        {
            square->GetBomb()->UpdateTimer(elapsedTime);
            if (square->HasBombExploded())
            {
                int rangeBomb = square->GetBomb()->GetRange();
                square->ClearBomb();
                std::get<2>((*bomb))->SetPlacedBomb(false);
                bomb = activeBombs.erase(bomb);
              
                UpdateMap(square->GetPosition(), rangeBomb);

            }
            else
            {
                bomb++;
            }

        }
    }


}

void Game::UpdateMap(std::pair<int,int> position,int rangeBomb)
{
    std::vector<std::pair<int, int>> directions = {
          { 0, 1}, 
          { 0, -1}, 
          { 1, 0}, 
          {-1, 0}  
    };
    int row = position.first;
    int col = position.second;
    for (auto& direction : directions)
    {
        for (int distance = 0; distance < rangeBomb; distance++)
        {
            int targetRow = row + (distance+1) * direction.first;
            int targetCol = col + (distance + 1) * direction.second;
            if (targetRow < 0 || targetCol < 0 || targetRow >= map->GetMapDimensions().first || targetCol >= map->GetMapDimensions().second){
                break; 
            }
            ISquare* targetSquare = map->GetSquare(targetRow, targetCol);
            if (targetSquare->GetPlayer())
            {
                this->SetGameOver();
            }
            if (targetSquare->GetSquareType() != ESquareType::Grass)
            {
                if (targetSquare->GetSquareType() == ESquareType::Wall)
                {
                    targetSquare->SetSquareType(ESquareType::Grass);
                    targetSquare->SetImagePath("../Bomberman.API/Assets/grass.png");

                }
                break;

            }

        }

    }

}
