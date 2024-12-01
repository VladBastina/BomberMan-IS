#include "Map.h"
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <iostream>

Map::Map(IPlayer* player1, IPlayer* player2, EMapInitialization mapInitialization)
{
    if(mapInitialization == EMapInitialization::Random)
        Initialize(player1, player2);
    else
        LoadFromFile(Constants::BoardTxtPath, player1, player2);
}

void Map::Initialize(IPlayer* player1, IPlayer* player2)
{
    ResetMap();

    for (int line = 0; line < 14; line++) {
        std::vector<ISquare*> lineVector;
        for (int col = 0; col < 14; col++) {
            ISquare* square = nullptr;

            // 1. Edges: Set to UnbreakableWall
            if (line == 0 || line == 13 || col == 0 || col == 13) {
                square = new Square(
                    std::make_pair(line, col),
                    nullptr,
                    ESquareType::UnbreakableWall,
                    Constants::WallUnbreakablePNGPath
                );
            }
            // 2. Grass areas
            else if ((line == 1 && (col == 1 || col == 2)) ||
                (line == 12 && (col == 12 || col == 11)) ||
                (line == 2 && col == 1) ||
                (line == 11 && col == 12)) {
                square = new Square(
                    std::make_pair(line, col),
                    nullptr,
                    ESquareType::Grass,
                    Constants::GrassPNGPath
                );
            }
            // 3. Remaining cells: randwom between Grass and Wall
            else
            {
                static std::random_device rd;
                static std::mt19937 gen(rd());
                static std::uniform_int_distribution<> dis(0, 1);

                if (dis(gen) == 0) {
                    square = new Square(
                        std::make_pair(line, col),
                        nullptr,
                        ESquareType::Grass,
                        Constants::GrassPNGPath
                    );
                }
                else {
                    square = new Square(
                        std::make_pair(line, col),
                        nullptr,
                        ESquareType::Wall,
                        Constants::WallBreakablePNGPath
                    );
                }
            }

            lineVector.push_back(square);
        }
        board.push_back(lineVector);
    }

    board[1][1]->SetPlayer(player1);
    board[12][12]->SetPlayer(player2);
}


void Map::ResetMap()
{
    for (int i = 0; i < board.size(); i++)
    {
        board[i].clear();
    }
    board.clear();
}

std::pair<int, int> Map::GetMapDimensions() const
{
    return std::make_pair(board.size(), board[0].size());
}

std::vector<std::vector<ISquare*>> Map::getBoard() const
{
    return board;
}

ISquare* Map::GetSquare(int x, int y) const
{
    return board[x][y];
}

bool Map::IsDestructible(int x, int y) const
{
    if (board[x][y]->GetSquareType() == ESquareType::UnbreakableWall)
    {
        return false;
    }
    return true;
}

bool Map::IsPassable(int x, int y) const
{
    if (board[x][y]->GetSquareType() == ESquareType::Wall || board[x][y]->GetSquareType() == ESquareType::UnbreakableWall)
    {
        return false;
    }
    return true;
}

bool Map::HasPowerUp(int x, int y) const
{
    return false;
}

bool Map::HasBombOnSquare(std::pair<int, int> position) const
{
    return this->board[position.first][position.second]->HasBomb();
}

std::vector<std::pair<int, int>> Map::GetExplosionRange(int x, int y, int explosionRadius) const
{
    return std::vector<std::pair<int, int>>();
}

bool Map::IsValidPosition(int x, int y) const
{
    if (x < board.size() && y < board[0].size())
    {
        return true;
    }
    return false;
}

void Map::UpdateSquare(int x, int y, ISquare* newSquare)
{
}

void Map::PlaceBomb(int x, int y)
{

    IBomb* bomb = new Bomb(std::make_pair(x, y),2,3);
    this->board[x][y]->SetBomb(bomb);

}

void Map::RemoveBomb(int x, int y)
{
}

void Map::AddPowerUp(int x, int y, ISquare* powerUp)
{
}

void Map::RemovePowerUp(int x, int y)
{
}

void Map::MovePlayer(IPlayer* player, EPlayerMovementType movementDir)
{
    //std::pair<int, int> playerPosition = player->GetPosition();
    //switch (movementDir)
    //{
    //case EPlayerMovementType::Up:
    //{
    //   /* if (playerPosition.first == 1)
    //        break;
    //    else
    //    {*/
    //        ISquare* square = GetSquare(playerPosition.first - 1, playerPosition.second);
    //        if (square->HasWall() && !square->HasPlayer())
    //        {
    //            square->SetPlayer(player);
    //            ISquare* currentSquare = GetSquare(playerPosition.first, playerPosition.second);
    //            currentSquare->RemovePlayer();
    //        }
    //    //}
    //    break;
    //}
    //case EPlayerMovementType::Down:
    //{
    //    /*if (playerPosition.first == 12)
    //        break;
    //    else
    //    {*/
    //        ISquare* square = GetSquare(playerPosition.first + 1, playerPosition.second);
    //        if (square->HasWall() && !square->HasPlayer())
    //        {
    //            square->SetPlayer(player);
    //            ISquare* currentSquare = GetSquare(playerPosition.first, playerPosition.second);
    //            currentSquare->RemovePlayer();
    //        }
    //    //}
    //    break;
    //}
    //case EPlayerMovementType::Left:
    //{
    //    /*if (playerPosition.second == 1)
    //        break;
    //    else
    //    {*/
    //        ISquare* square = GetSquare(playerPosition.first, playerPosition.second - 1);
    //        if (square->HasWall() && !square->HasPlayer())
    //        {
    //            square->SetPlayer(player);
    //            ISquare* currentSquare = GetSquare(playerPosition.first, playerPosition.second);
    //            currentSquare->RemovePlayer();
    //        }
    //    //}
    //    break;
    //}
    //case EPlayerMovementType::Right:
    //{
    //    /*if (playerPosition.second == 12)
    //        break;
    //    else
    //    {*/
    //        ISquare* square = GetSquare(playerPosition.first, playerPosition.second + 1);
    //        if (square->HasWall() && !square->HasPlayer())
    //        {
    //            square->SetPlayer(player);
    //            ISquare* currentSquare = GetSquare(playerPosition.first, playerPosition.second);
    //            currentSquare->RemovePlayer();
    //        }
    //    //}
    //    break;
    //}
    //}
}

void Map::LoadFromFile(std::string filePath, IPlayer* player1, IPlayer* player2)
{
    ResetMap();

    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file 'board_layout.txt'" << std::endl;
    }

    int line = 0;
    std::string row;
    while (std::getline(file, row) && line < 14) {
        std::istringstream rowStream(row);
        std::vector<ISquare*> lineVector;
        int col = 0;
        int value;

        while (rowStream >> value && col < 14) {
            ISquare* square = nullptr;
            if (value == 0) {
                square = new Square(
                    std::make_pair(line, col),
                    nullptr,
                    ESquareType::UnbreakableWall,
                    Constants::WallUnbreakablePNGPath
                );
            }
            else if (value == 1) {
                square = new Square(
                    std::make_pair(line, col),
                    nullptr,
                    ESquareType::Grass,
                    Constants::GrassPNGPath
                );
            }
            else if (value == 2) {
                square = new Square(
                    std::make_pair(line, col),
                    nullptr,
                    ESquareType::Wall,
                    Constants::WallBreakablePNGPath
                );
            }
            else {
                std::cerr << "Warning: Invalid value at (" << line << ", " << col << "). Defaulting to Grass." << std::endl;
                square = new Square(
                    std::make_pair(line, col),
                    nullptr,
                    ESquareType::Grass,
                    Constants::GrassPNGPath
                );
            }

            lineVector.push_back(square);
            ++col;
        }

        if (col != 14) {
            std::cerr << "Error: Row " << line << " does not contain 14 columns!" << std::endl;
        }

        board.push_back(lineVector);
        ++line;
    }

    if (line != 14) {
        std::cerr << "Error: File does not contain 14 rows!" << std::endl;
    }

    file.close();

    board[1][1]->SetPlayer(player1);
    board[12][12]->SetPlayer(player2);

}


