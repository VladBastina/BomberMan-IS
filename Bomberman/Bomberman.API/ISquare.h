#pragma once
#include "IPlayer.h"
#include <functional>


enum ESquareType
{
	Grass = 0,
	Wall = 1,
	UnbrakableWall = 2
};

class ISquare {
public:
	virtual ~ISquare() = default;

	virtual std::pair<int, int> GetPosition() = 0;
	virtual bool HasPlayer() = 0;
	virtual ESquareType HasWall() = 0;
	virtual bool HasPowerUp() = 0;
	virtual IPlayer* GetPlayer() = 0;
	//virtual IPowerUp GetPowerUp() = 0;

	virtual void SetPlayer(IPlayer* player) = 0;
	//virtual void SetPowerUp(IPoewerUp powerUp) = 0;

	virtual bool BreakWall() = 0;

private:

	virtual void DropPowerUp() = 0;

};