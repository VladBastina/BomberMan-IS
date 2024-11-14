#include "Square.h"

std::pair<int, int> Square::GetPosition()
{
    return std::pair<int, int>();
}

bool Square::HasPlayer()
{
    return false;
}

ESquareType Square::HasWall()
{
    return ESquareType();
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
}

bool Square::BreakWall()
{
    return false;
}

void Square::DropPowerUp()
{
}
