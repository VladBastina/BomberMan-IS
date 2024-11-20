#pragma once
#include "IGameListener.h"
#include "Map.h"

class IGame
{
public:
	virtual ~IGame() = default;

	virtual void addGameListener(IGameListener* listener) = 0;
	virtual void removeGameListener(IGameListener* listener) = 0;
	virtual IMap* getMap() = 0;
	virtual bool isOver() = 0;
	virtual void SetGameOver() = 0;
	virtual void MovePlayer(EPlayerType playerType, EPlayerMovementType movementDir) = 0;
	virtual void MovePlayer(IPlayer* player, EPlayerMovementType movementDir) = 0;
	virtual IPlayer* GetPlayer1() = 0;
	virtual IPlayer* GetPlayer2() = 0;
};

