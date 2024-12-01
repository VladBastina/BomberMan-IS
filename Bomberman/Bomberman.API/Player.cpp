#include "Player.h"

Player::Player(EPlayerType playerType, int startX, int startY)
    : type(playerType), position(startX, startY), alive(true), placedBomb(false), activePowerup(false)
{
    imagePath = type == EPlayerType::One ? Constants::Player1PNGPath : Constants::Player2PNGPath;
    if (!ImageExist(imagePath)) {
        std::cerr << "Image does not exist: " << imagePath << std::endl;
    }
    lastMoveTime = std::chrono::steady_clock::now();
    moveDelay = 0.4f;
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

std::chrono::steady_clock::time_point Player::GetLastMoveTime() const
{
    return lastMoveTime;
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

void Player::SetLastMoveTime(const std::chrono::steady_clock::time_point& newTime)
{
    lastMoveTime = newTime;
}

bool Player::CanMove()
{
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastMoveTime).count();
    return elapsed >= (moveDelay * 1000);
}

bool Player::ImageExist(const std::string& path)
{
    std::ifstream file(path);
    return file.good();
}