#pragma once

#include <utility>

class IGameListener {
public:
    virtual ~IGameListener() = default;

    virtual void OnPlayerMoved(int newX, int newY) = 0;
    virtual void OnPlayerPlacedBomb(int x, int y) = 0;
    virtual void OnPlayerDestroyed() = 0;
};