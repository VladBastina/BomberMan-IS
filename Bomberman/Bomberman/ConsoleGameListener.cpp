#include "ConsoleGameListener.h"
#include <windows.h>
#include <iostream>
#include <string>


std::wstring ConvertToWideString(const std::string& narrowString) 
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, narrowString.c_str(), -1, NULL, 0);
    std::wstring wideString(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, narrowString.c_str(), -1, &wideString[0], size_needed);
    return wideString;
}

void ConsoleGameListener::OnPlayerMoved(int newX, int newY)
{
    std::cout << "Player moved to position (" << newX << ", " << newY << ")." << std::endl;
    std::string message = "Player moved to position (" + std::to_string(newX) + ", " + std::to_string(newY) + ").";
    std::wstring wideMessage = ConvertToWideString(message);
    OutputDebugString(wideMessage.c_str());
}

void ConsoleGameListener::OnPlayerPlacedBomb(int x, int y)
{
    std::cout << "Bomb placed at position (" << x << ", " << y << ")." << std::endl;
    std::string message = "Bomb placed at position" + std::to_string(x) + ", " + std::to_string(y) + ").";
    std::wstring wideMessage = ConvertToWideString(message);
    OutputDebugString(wideMessage.c_str());
}

void ConsoleGameListener::OnPlayerDestroyed()
{
    std::cout << "A player has been destroyed. Game Over!" << std::endl;
    std::string message = "A player has been destroyed. Game Over!";
    std::wstring wideMessage = ConvertToWideString(message);
    OutputDebugString(wideMessage.c_str());
}