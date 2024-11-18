#pragma once
#ifndef IPLAYERLISTENER_H
#define IPLAYERLISTENER_H

#include <utility>

class IPlayerListener {
public:
    virtual ~IPlayerListener() = default;

    virtual void OnPlayerMoved(int newX, int newY) = 0;
    virtual void OnPlayerPlacedBomb(int x, int y) = 0;
    virtual void OnPlayerDestroyed() = 0;
};

#endif
