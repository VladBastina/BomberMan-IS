#pragma once
#include "IPlayer.h"
#include "Bomb.h"
#include <string>
#include <utility>
#include "ESquareType.h"


class ISquare {
public:
    virtual ~ISquare() = default;

    // Information Querying
    virtual std::pair<int, int> GetPosition() const = 0;
    virtual bool HasPlayer() const = 0;
    virtual ESquareType GetSquareType() const = 0;
    virtual bool HasPowerUp() const = 0;
    virtual bool HasBomb() const = 0;
    virtual bool HasBombExploded() const = 0;
    virtual IPlayer* GetPlayer() const = 0;
    virtual IBomb* GetBomb() const = 0;
    virtual std::string GetImagePath() const = 0;
    virtual bool HasWall() const = 0;

    // Modification
    virtual void SetPlayer(IPlayer* player) = 0;
    virtual void SetBomb(IBomb* bomb) = 0;
    virtual void SetSquareType(ESquareType squareType) = 0;
    virtual void SetImagePath(std::string imagePath) = 0;
    virtual void RemovePlayer() = 0;
    virtual bool BreakWall() = 0;
    virtual void ClearBomb() = 0;

private:
    virtual void DropPowerUp() = 0;
};
