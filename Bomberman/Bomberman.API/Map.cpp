#include "Map.h"

Map::Map(IPlayer* player1, IPlayer* player2)
{
    Initialize(player1, player2);
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
                    "../Bomberman.API/Assets/wall_unbreakable.png"
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
                    "../Bomberman.API/Assets/grass.png"
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
                        "../Bomberman.API/Assets/grass.png"
                    );
                }
                else {
                    square = new Square(
                        std::make_pair(line, col),
                        nullptr,
                        ESquareType::Wall,
                        "../Bomberman.API/Assets/wall_breakable.png"
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
    if (board[x][y]->GetWallType() == ESquareType::UnbreakableWall)
    {
        return false;
    }
    return true;
}

bool Map::IsPassable(int x, int y) const
{
    if (board[x][y]->GetWallType() == ESquareType::Wall || board[x][y]->GetWallType() == ESquareType::UnbreakableWall)
    {
        return false;
    }
    return true;
}

bool Map::HasBomb(int x, int y) const
{
    return false;
}

bool Map::HasPowerUp(int x, int y) const
{
    return false;
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


