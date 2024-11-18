#pragma once
#include <SFML/Graphics.hpp>




class Game 
{
private :
	sf::Rende







};



#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Bomberman");
    sf::Event e;

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}