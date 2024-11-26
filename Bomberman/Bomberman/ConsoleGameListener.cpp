#include "ConsoleGameListener.h"

#include <iostream>

void ConsoleGameListener::OnPlayerMoved(int newX, int newY)
{
    std::cout << "Player moved to position (" << newX << ", " << newY << ")." << std::endl;
}

void ConsoleGameListener::OnPlayerPlacedBomb(int x, int y)
{
    std::cout << "Bomb placed at position (" << x << ", " << y << ")." << std::endl;
}

void ConsoleGameListener::OnPlayerDestroyed()
{
    std::cout << "A player has been destroyed. Game Over!" << std::endl;
}