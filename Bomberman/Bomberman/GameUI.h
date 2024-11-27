#pragma once
#define NOMINMAX
#include <windows.h>
#include <SFML/Graphics.hpp>
#include "Game.h"


class GameUI : public IGameListener
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	IGame* game;
	std::map<std::string, sf::Texture> textureCache;

	sf::Texture gameOverTexture; // Texture for the "Game Over" screen
	sf::Sprite gameOverSprite;   // Sprite for the "Game Over" screen

	void initVariables();
	void initWindow();

public:
	GameUI();
	virtual ~GameUI();


	void startNewGame();
	void OnKeyPressed(float elapsedTime);
	void pollEvents();
	void render();
	void renderSquare(const ISquare* square);
	
	const bool running() const;

	// Inherited via IGameListener
	void OnKeyPressed() override;
};