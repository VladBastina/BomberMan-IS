#pragma once
#include "IPlayer.h"
#include <vector>
#include <fstream>
#include <algorithm> // for std::remove
#include <iostream>


class Player : public IPlayer {
private:
    EPlayerType type;
    std::pair<int, int> position;
    bool alive;
    bool placedBomb;
    std::string imagePath;
    bool activePowerup;

    // List of listeners
    std::vector<IPlayerListener*> listeners;


    bool ImageExist(const std::string& path);

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

    // Setters
    void SetPosition(int x, int y) override;
    void SetAlive(bool isAlive) override;
    void SetPlacedBomb(bool hasPlaced) override;
    void SetImagePath(const std::string& path) override;
    void SetActivePowerup(bool active) override;

    // Listener management
    void addPlayerListener(IPlayerListener* listener) override;
    void removePlayerListener(IPlayerListener* listener) override;

    // Game-specific methods
    /*void OnDestroy() override;
    void OnPlaceBomb() override;
    void OnPlayerMove(int dx, int dy) override;*/

private:

    // Helper to notify listeners
    /*void notifyPlayerMoved();
    void notifyPlayerPlacedBomb();
    void notifyPlayerDestroyed();*/
};

