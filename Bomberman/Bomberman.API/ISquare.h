#pragma once
#include "IPlayer.h"
#include <string>
#include <utility>

enum class ESquareType
{
    Grass = 0,
    Wall = 1,
    UnbreakableWall = 2
};

class ISquare {
public:
    virtual ~ISquare() = default;

    // Information Querying
    virtual std::pair<int, int> GetPosition() const = 0;
    virtual bool HasPlayer() const = 0;
    virtual ESquareType GetWallType() const = 0;
    virtual bool HasPowerUp() const = 0;
    virtual IPlayer* GetPlayer() const = 0;
    virtual std::string GetImagePath() const = 0;

    // Modification
    virtual void SetPlayer(IPlayer* player) = 0;
    virtual void RemovePlayer() = 0;
    virtual bool BreakWall() = 0;

private:
    virtual void DropPowerUp() = 0;
};
