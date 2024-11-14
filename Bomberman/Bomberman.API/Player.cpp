#include "Player.h"
#include <algorithm> // for std::remove
#include <iostream>

// Constructor
Player::Player(EPlayerType playerType, int startX, int startY, const std::string& image)
    : type(playerType), position(startX, startY), alive(true), placedBomb(false), imagePath(image), activePowerup(false) {
}

// Getters
EPlayerType Player::GetType() const {
    return type;
}

std::pair<int, int> Player::GetPosition() const {
    return position;
}

bool Player::IsAlive() const {
    return alive;
}

bool Player::HasPlacedBomb() const {
    return placedBomb;
}

std::string Player::GetImagePath() const {
    return imagePath;
}

bool Player::HasActivePowerup() const {
    return activePowerup;
}

// Setters
void Player::SetPosition(int x, int y) {
    position = std::make_pair(x, y);
    //notifyPlayerMoved(); // Notify listeners of movement
}

void Player::SetAlive(bool isAlive) {
    alive = isAlive;
}

void Player::SetPlacedBomb(bool hasPlaced) {
    placedBomb = hasPlaced;
}

void Player::SetImagePath(const std::string& path) {
    imagePath = path;
}

void Player::SetActivePowerup(bool active) {
    activePowerup = active;
}

// Listener management
void Player::addPlayerListener(IPlayerListener* listener) {
    listeners.push_back(listener);
}

void Player::removePlayerListener(IPlayerListener* listener) {
    listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
}

// Game-specific methods
//void Player::OnDestroy() {
//    alive = false;
//    std::cout << "Player of type " << (type == EPlayerType::One ? "One" : "Two") << " was destroyed.\n";
//    notifyPlayerDestroyed(); // Notify listeners of destruction
//}
//
//void Player::OnPlaceBomb() {
//    placedBomb = true;
//    std::cout << "Player of type " << (type == EPlayerType::One ? "One" : "Two") << " placed a bomb.\n";
//    notifyPlayerPlacedBomb(); // Notify listeners of bomb placement
//}
//
//void Player::OnPlayerMove(int dx, int dy) {
//    position.first += dx;
//    position.second += dy;
//    std::cout << "Player of type " << (type == EPlayerType::One ? "One" : "Two")
//        << " moved to position (" << position.first << ", " << position.second << ").\n";
//    notifyPlayerMoved(); // Notify listeners of movement
//}
//
//// Helper functions to notify listeners
//void Player::notifyPlayerMoved() {
//    for (IPlayerListener* listener : listeners) {
//        listener->OnPlayerMoved(position.first, position.second);
//    }
//}
//
//void Player::notifyPlayerPlacedBomb() {
//    for (IPlayerListener* listener : listeners) {
//        listener->OnPlayerPlacedBomb(position.first, position.second);
//    }
//}
//
//void Player::notifyPlayerDestroyed() {
//    for (IPlayerListener* listener : listeners) {
//        listener->OnPlayerDestroyed();
//    }
//}