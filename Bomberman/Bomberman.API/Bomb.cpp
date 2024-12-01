#include "Bomb.h"

Bomb::Bomb(std::pair<int, int> position, int range,float timer): position(position), range(range), timer(timer)
{
	imagePath = "../Bomberman.API/Assets/bomb.png";
	/*if (!ImageExist(imagePath)) {
		std::cerr << "Image does not exist: " << imagePath << std::endl;
	}*/

}

std::pair<int, int> Bomb::GetPosition() const
{
	return position;
}

int Bomb::GetRange() const
{
	return range;
}

std::chrono::steady_clock::time_point Bomb::GetTimer() const
{
	return placedBombTime;
}

std::string Bomb::GetImagePath() const
{
	return imagePath;
}

void Bomb::SetPosition(std::pair<int, int> position)
{
	this->position = position;
}

void Bomb::SetRange(int range)
{
	this->range = range;
}

void Bomb::SetTimer(const std::chrono::steady_clock::time_point& timer)
{
	this->placedBombTime = timer;
}

void Bomb::SetImagePath(const std::string& path)
{
	imagePath = path;
}

bool Bomb::HasExploded() const
{
	return timer <= 0;
}

void Bomb::UpdateTimer(float elapsedTime)
{
	timer -= elapsedTime;

}

//void Bomb::Explode()
//{
//	exploded=tr
//}
