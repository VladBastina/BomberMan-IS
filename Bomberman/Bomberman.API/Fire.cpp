#include "Fire.h"
#include "Constants.h"

Fire::Fire(std::pair<int, int> position, float timer): position{position}, timer{timer}
{
    imagePath = Constants::FirePNGPath;
}

std::pair<int, int> Fire::GetPosition() const
{
    return position;
}

float Fire::GetTimer() const
{
    return timer;
}

std::string Fire::GetImagePath() const
{
    return imagePath;
}

void Fire::SetPosition(const std::pair<int, int>& position)
{
    this->position = position;
}

void Fire::SetTimer(const float& timer)
{
    this->timer = timer;
}

bool Fire::HasExpired(const float& elapsedTime)
{
    timer -= elapsedTime;
    return timer <= 0.0f;

}
