#pragma once
#define NOMINMAX
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "Game.h"


class GameUI 
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	IGame* game;
	std::map<std::string, sf::Texture> textureCache;

	void initVariables();
	void initWindow();

public:
	GameUI();
	virtual ~GameUI();

	void update();
	void pollEvents();
	void render();
	void renderSquare(const ISquare* square);
	
	const bool running() const;
};