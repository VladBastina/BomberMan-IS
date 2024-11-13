#pragma once
#ifndef IPLAYER_H
#define IPLAYER_H

#include <utility>
#include <string>
#include <vector>
#include "EPlayerType.h"
#include "IPlayerListener.h"

class IPlayer {
public:
    virtual ~IPlayer() = default;

    // Getters
    virtual EPlayerType GetType() const = 0;
    virtual std::pair<int, int> GetPosition() const = 0;
    virtual bool IsAlive() const = 0;
    virtual bool HasPlacedBomb() const = 0;
    virtual std::string GetImagePath() const = 0;
    virtual bool HasActivePowerup() const = 0;

    // Setters
    virtual void SetPosition(int x, int y) = 0;
    virtual void SetAlive(bool alive) = 0;
    virtual void SetPlacedBomb(bool placed) = 0;
    virtual void SetImagePath(const std::string& path) = 0;
    virtual void SetActivePowerup(bool active) = 0;

    // Listeners
    virtual void addPlayerListener(IPlayerListener* listener) = 0;
    virtual void removePlayerListener(IPlayerListener* listener) = 0;

    // Game-specific methods
    /*virtual void OnDestroy() = 0;
    virtual void OnPlaceBomb() = 0;
    virtual void OnPlayerMove(int dx, int dy) = 0;*/
};

#endif