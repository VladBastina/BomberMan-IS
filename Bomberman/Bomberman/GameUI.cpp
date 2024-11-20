#include "GameUI.h"
#include <iostream>

void GameUI::initVariables()
{
	this->window = nullptr;
}

void GameUI::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Bomberman");
	game = new Game();
}

GameUI::GameUI()
{
	this->initVariables();
	this->initWindow();
}

GameUI::~GameUI()
{
	delete this->window;
	delete this->game;
}

void GameUI::update()
{
	this->pollEvents();

}

void GameUI::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void GameUI::render()
{
	///*
	//	return void:
	//	- clear 


	//	Renders the GameUI objects
	//
	//*/
	//this->window->clear(sf::Color(255, 0, 0, 0));

	//// Draw GameUI objects

	if (!this->game) {
		std::cerr << "Error: Game is not initialized!" << std::endl;
		return;
	}

	IMap* map = this->game->getMap();
	if (!map) {
		std::cerr << "Error: Map is not initialized!" << std::endl;
		return;
	}

	//this->window->display();
	this->window->clear();

	const auto& board = this->game->getMap()->getBoard(); // Access the map's board
	for (const auto& row : board) {
		for (const auto* square : row) {
			if (square) {
				renderSquare(square); // Render each square
			}
		}
	}

	this->window->display();
}

void GameUI::renderSquare(const ISquare* square)
{
	// Get the image path
	std::string imagePath = square->GetImagePath();

	// Load texture if not cached
	if (textureCache.find(imagePath) == textureCache.end()) {
		sf::Texture texture;
		if (!texture.loadFromFile(imagePath)) {
			std::cerr << "Failed to load texture: " << imagePath << std::endl;
			return;
		}
		textureCache[imagePath] = std::move(texture); // Store in cache
	}

	// Create a sprite for the square
	sf::Sprite sprite(textureCache[imagePath]);

	// Set the sprite's position
	std::pair<int, int> position = square->GetPosition();
	int row = position.first;
	int col = position.second;

	sprite.setPosition(static_cast<float>(col * 50), static_cast<float>(row * 50)); // 50x50 grid

	// Draw the sprite
	this->window->draw(sprite);
}

const bool GameUI::running() const
{
	return this->window->isOpen();
}
