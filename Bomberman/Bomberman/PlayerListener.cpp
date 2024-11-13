#include "PlayerListener.h"

#include <iostream>

void PlayerListener::OnPlayerMoved()
{
	std::cout << "You moved the player." << std::endl;
}

void PlayerListener::OnPlayerPlacedBomb()
{
	std::cout << "You placed a bomb." << std::endl;
}

void PlayerListener::OnPlayerDestroyed()
{
	std::cout << "Player destroyed." << std::endl;
}