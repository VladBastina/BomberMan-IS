#pragma once
#include "IPlayer.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>

class Player : public IPlayer {
private:
    EPlayerType type;
    std::pair<int, int> position;
    bool alive;
    bool placeBomb;
    std::string imagePath;
    bool activePowerup;
    std::chrono::steady_clock::time_point lastMoveTime;
    float moveDelay;


public:
    // Constructor
    Player(EPlayerType playerType, int startX, int startY);

    // Getters
    EPlayerType GetType() const override;
    std::pair<int, int> GetPosition() const override;
    bool IsAlive() const override;
    bool HasPlacedBomb() const override;
    std::string GetImagePath() const override;
    bool HasActivePowerup() const override;
    std::chrono::steady_clock::time_point GetLastMoveTime() const;

    // Setters
    void SetPosition(int x, int y) override;
    void SetAlive(bool isAlive) override;
    void StatePlaceBomb() override;
    void SetImagePath(const std::string& path) override;
    void SetActivePowerup(bool active) override;
    void SetLastMoveTime(const std::chrono::steady_clock::time_point& newTime);
    bool CanMove() override;
};

