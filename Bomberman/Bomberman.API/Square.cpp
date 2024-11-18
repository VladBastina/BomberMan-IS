#include "Square.h"

Square::Square(std::pair<int, int> pos, IPlayer* player, ESquareType squareType, std::string imagePath)
{
    this->position = pos;
    this->player = player;
    this->squareType = squareType;
    this->imagePath = imagePath;
}

std::pair<int, int> Square::GetPosition()
{
    return position;
}

bool Square::HasPlayer()
{
    if (player)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ESquareType Square::HasWall()
{
    return squareType;
}

bool Square::HasPowerUp()
{
    return false;
}

IPlayer* Square::GetPlayer()
{
    return player;
}

void Square::SetPlayer(IPlayer* player)
{
    this->player = player;
}

bool Square::BreakWall()
{
    return false;
}

void Square::DropPowerUp()
{
}

std::string Square::GetImagePath()
{
    return imagePath;
}
