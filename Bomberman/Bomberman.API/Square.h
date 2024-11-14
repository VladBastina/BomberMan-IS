#pragma once
#include "ISquare.h"

class Square : public ISquare
{
public:
	// Inherited via ISquare
	std::pair<int, int> GetPosition() override;
	bool HasPlayer() override;
	ESquareType HasWall() override;
	bool HasPowerUp() override;
	IPlayer* GetPlayer() override;
	void SetPlayer(IPlayer* player) override;
	bool BreakWall() override;
private:
	void DropPowerUp() override;


	IPlayer* player;
};

