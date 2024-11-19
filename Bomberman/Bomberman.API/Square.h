#pragma once
#include "ISquare.h"

class Square : public ISquare
{
public:
	Square(std::pair<int,int>pos,IPlayer* player , ESquareType squareType , std::string imagePath);
	~Square() = default;

	// Inherited via ISquare
	std::pair<int, int> GetPosition() const override;
	bool HasPlayer() const override;
	ESquareType GetWallType() const override;
	bool HasPowerUp() const override;
	IPlayer* GetPlayer() const override;
	std::string GetImagePath() const override;

	void SetPlayer(IPlayer* player) override;
	void RemovePlayer() override;
	bool BreakWall() override;
	void DropPowerUp() override;

private:

	std::pair<int, int> position;
	IPlayer* player;
	ESquareType squareType;
	std::string imagePath;
	//IPowerUp powerUp;
};

