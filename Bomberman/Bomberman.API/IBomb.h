#pragma once
#include <utility>
#include <string>
#include <chrono>
class IBomb {
public:
	virtual ~IBomb()=default;

	//Getters
	virtual std::pair<int,int> GetPosition() const = 0;
	virtual int GetRange() const = 0;
	virtual std::chrono::steady_clock::time_point GetTimer() const = 0;
	virtual std::string GetImagePath() const = 0;

	//Setters
	virtual void SetPosition(std::pair<int, int> position) = 0;
	virtual void SetRange(int range) = 0;
	virtual void SetTimer(const std::chrono::steady_clock::time_point& timer) = 0;
	virtual void SetImagePath(const std::string& imagePath) = 0;

	// virtual void Explode() = 0;
};