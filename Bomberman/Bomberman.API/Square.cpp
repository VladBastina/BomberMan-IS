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
    return position;
}

bool Square::HasPlayer() const
{
    if (player != nullptr)
    {
        return true;
    }
    return false;
}

ESquareType Square::GetWallType() const
{
    return squareType;
}

bool Square::HasPowerUp() const
{
    return false;
}

IPlayer* Square::GetPlayer() const
{
    return player;
}

std::string Square::GetImagePath() const
{
    return imagePath;
}

void Square::SetPlayer(IPlayer* player)
{
    this->player = player;
    this->player->SetPosition(this->position.first,this->position.second);
}

void Square::RemovePlayer()
{
    player = nullptr;
}

bool Square::BreakWall()
{
    if (squareType == ESquareType::Wall)
    {
        squareType = ESquareType::Grass;
        DropPowerUp();
        return true;
    }
    else if (squareType == ESquareType::UnbreakableWall)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Square::DropPowerUp()
{

}



