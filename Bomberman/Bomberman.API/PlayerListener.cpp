#include "PlayerListener.h"

#include <iostream>

void PlayerListener::OnPlayerMoved(int x, int y)
{
	std::cout << "You moved the player." << std::endl;
}

void PlayerListener::OnPlayerPlacedBomb(int x, int y)
{
	std::cout << "You placed a bomb." << std::endl;
}

void PlayerListener::OnPlayerDestroyed()
{
	std::cout << "Player destroyed." << std::endl;
}