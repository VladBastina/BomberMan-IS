#pragma once
#include "ISquare.h"

class Square : public ISquare
{
public:
	Square(std::pair<int,int>pos,IPlayer* player , ESquareType squareType , std::string imagePath);
	~Square() = default;

	// Inherited via ISquare
	std::pair<int, int> GetPosition() override;
	bool HasPlayer() override;
	ESquareType HasWall() override;
	bool HasPowerUp() override;
	IPlayer* GetPlayer() override;
	void SetPlayer(IPlayer* player) override;
	bool BreakWall() override;
	std::string GetImagePath() override;
private:
	void DropPowerUp() override;

	std::pair<int, int> position;
	IPlayer* player;
	ESquareType squareType;
	std::string imagePath;
	//IPowerUp powerUp;
};

