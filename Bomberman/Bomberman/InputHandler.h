#pragma once
#include <SFML/Graphics.hpp>
#include <Game.h>


static class InputHandler {
public:
    static void HandleKeyPress(sf::Event& event, IGame* game, sf::RenderWindow* window);

private:
    static void HandlePlayerMovement(sf::Event& event, IGame* game);

    static void HandleBombPlacement(sf::Event& event, IGame* game);
};


