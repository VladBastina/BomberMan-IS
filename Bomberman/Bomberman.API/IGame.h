#pragma once
#include "IGameListener.h"

class IGame
{
public:
	virtual ~IGame() = default;

	virtual void addGameListener(IGameListener* listener) = 0;
	virtual void removeGameListener(IGameListener* listener) = 0;
};

