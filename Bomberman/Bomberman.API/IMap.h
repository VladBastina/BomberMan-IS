#pragma once
#pragma once
#include <vector>
#include <string>
#include <utility>
#include "Square.h"


class IMap {


public:
    // Initialization and Configuration
    virtual void Initialize(IPlayer* player1, IPlayer* player2) = 0;
    virtual void ResetMap() = 0;
    virtual std::pair<int, int> GetMapDimensions() const = 0;
    virtual std::vector<std::vector<ISquare*>> getBoard() const = 0;

    // State Querying
    virtual ISquare* GetSquare(int x, int y) const = 0;
    virtual bool IsDestructible(int x, int y) const = 0;
    virtual bool IsPassable(int x, int y) const = 0;
    virtual bool HasPowerUp(int x, int y) const = 0;
    virtual bool HasBombOnSquare(std::pair<int, int> position) const = 0;

    // Utility Functions
    virtual std::vector<std::pair<int, int>> GetExplosionRange(int x, int y, int explosionRadius) const = 0;
    virtual bool IsValidPosition(int x, int y) const = 0;

    // Map Updates
    virtual void UpdateSquare(int x, int y, ISquare* newSquare) = 0;
    virtual void PlaceBomb(int x, int y) = 0;
    virtual void RemoveBomb(int x, int y) = 0;
    virtual void AddPowerUp(int x, int y, ISquare* powerUp) = 0;
    virtual void RemovePowerUp(int x, int y) = 0;

    virtual void MovePlayer(IPlayer* player, EPlayerMovementType movementDir) = 0;

    virtual void LoadFromFile(std::string filePath, IPlayer* player1, IPlayer* player2) = 0;


    // Virtual destructor to ensure proper cleanup of derived classes.
    virtual ~IMap() = default;
};

