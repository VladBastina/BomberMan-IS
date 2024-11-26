#pragma once
#include "IGameListener.h"

class ConsoleGameListener : public IGameListener
{
public:
	virtual void OnPlayerMoved(int newX, int newY);
	virtual void OnPlayerPlacedBomb(int x, int y);
	virtual void OnPlayerDestroyed();
};


