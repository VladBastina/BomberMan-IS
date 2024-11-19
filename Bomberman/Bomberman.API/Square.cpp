#include "Square.h"

Square::Square(std::pair<int, int> pos, IPlayer* player, ESquareType squareType, std::string imagePath)
{
    this->position = pos;
    this->player = player;
    this->squareType = squareType;
    this->imagePath = imagePath;
}

std::pair<int, int> Square::GetPosition() const
{
    return std::pair<int, int>();
}

bool Square::HasPlayer() const
{
    return false;
}

ESquareType Square::GetWallType() const
{
    return ESquareType();
}

bool Square::HasPowerUp() const
{
    return false;
}

IPlayer* Square::GetPlayer() const
{
    return nullptr;
}

std::string Square::GetImagePath() const
{
    return std::string();
}

void Square::SetPlayer(IPlayer* player)
{
}

void Square::RemovePlayer()
{
}

bool Square::BreakWall()
{
    return false;
}

void Square::DropPowerUp()
{
}



