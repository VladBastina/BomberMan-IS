#include "Map.h"

Map::Map()
{
}

void Map::Initialize()
{
}

void Map::ResetMap()
{
}

std::pair<int, int> Map::GetMapDimensions() const
{
    return std::pair<int, int>();
}

ISquare* Map::GetSquare(int x, int y) const
{
    return nullptr;
}

bool Map::IsDestructible(int x, int y) const
{
    return false;
}

bool Map::IsPassable(int x, int y) const
{
    return false;
}

bool Map::HasBomb(int x, int y) const
{
    return false;
}

bool Map::HasPowerUp(int x, int y) const
{
    return false;
}

std::vector<std::pair<int, int>> Map::GetAllDestructibleSquares() const
{
    return std::vector<std::pair<int, int>>();
}

std::vector<std::pair<int, int>> Map::GetExplosionRange(int x, int y, int explosionRadius) const
{
    return std::vector<std::pair<int, int>>();
}

bool Map::IsValidPosition(int x, int y) const
{
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

void Map::PrintMap() const
{
}

std::string Map::ExportMapAsString() const
{
    return std::string();
}

