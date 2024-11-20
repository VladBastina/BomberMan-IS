#pragma once
#include "IGameListener.h"
#include "IMap.h"

class IGame
{
public:
	virtual ~IGame() = default;

	virtual void addGameListener(IGameListener* listener) = 0;
	virtual void removeGameListener(IGameListener* listener) = 0;
	virtual IMap* getMap() = 0;
	virtual bool isOver() = 0;
	virtual void SetGameOver() = 0;
};

