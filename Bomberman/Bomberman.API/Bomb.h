#pragma once
#include "IBomb.h"
class Bomb : public IBomb {
private:
	std::pair<int, int> position;
	std::chrono::steady_clock::time_point placedBombTime;
	int explosionDelay;
	int range;
	std::string imagePath;
	//bool exploded;
public:

	//Constructor
	Bomb(std::pair<int, int> position, int range,int explosionDelay);

	//Getters

	std::pair<int, int> GetPosition() const override;
	int GetRange() const override;
	std::chrono::steady_clock::time_point GetTimer() const override;
    std::string GetImagePath() const override;
	void Countdown();

	//Setters

	void SetPosition(std::pair<int, int> position) override;
	void SetRange(int range) override;
	void SetTimer(const std::chrono::steady_clock::time_point& timer) override;
	void SetImagePath(const std::string& path) override;

	//void Explode() override;

};