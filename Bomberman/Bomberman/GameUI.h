#pragma once
#define NOMINMAX
#include <windows.h>
#include <SFML/Graphics.hpp>


class GameUI 
{
private:
	sf::RenderWindow* window;
	sf::Event ev;

	void initVariables();
	void initWindow();

public:
	GameUI();
	virtual ~GameUI();

	void update();
	void pollEvents();
	void render();
	
	const bool running() const;


};