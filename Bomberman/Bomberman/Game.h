#pragma once
#define NOMINMAX
#include <windows.h>
#include <SFML/Graphics.hpp>


class Game 
{
private:
	sf::RenderWindow* window;
	sf::Event ev;

	void initVariables();
	void initWindow();

public:
	Game();
	virtual ~Game();

	void update();
	void pollEvents();
	void render();
	
	const bool running() const;


};