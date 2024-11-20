#include "GameUI.h"
#include <iostream>

void GameUI::initVariables()
{
	this->game = new Game();
}

void GameUI::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Bomberman");
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
	this->window->clear();

	const auto& board = this->game->getMap()->getBoard();
	for (const auto& row : board) {
		for (const auto* square : row) {
			if (square) {
				renderSquare(square);
			}
		}
	}

	this->window->display();
}

void GameUI::renderSquare(const ISquare* square)
{
	std::string imagePath = square->GetImagePath();

	if (textureCache.find(imagePath) == textureCache.end()) {
		sf::Texture texture;
		if (!texture.loadFromFile(imagePath)) {
			std::cerr << "Failed to load texture: " << imagePath << std::endl;
			return;
		}
		textureCache[imagePath] = std::move(texture);
	}

	sf::Sprite sprite(textureCache[imagePath]);

	// since our pngs are 16/16 we need to scale them 
	float scaleX = 57.0f / 16.0f; // Grid cell width / Image width 
	float scaleY = 57.0f / 16.0f; // Grid cell height / Image height

	sprite.setScale(scaleX, scaleY);

	std::pair<int, int> position = square->GetPosition();
	int row = position.first;
	int col = position.second;

	sprite.setPosition(static_cast<float>(col * 57), static_cast<float>(row * 57));
	this->window->draw(sprite);

	IPlayer* player = square->GetPlayer();
	if (player) {
		std::string playerImagePath = player->GetImagePath();

		if (textureCache.find(playerImagePath) == textureCache.end()) {
			sf::Texture texture;
			if (!texture.loadFromFile(playerImagePath)) {
				std::cerr << "Failed to load texture: " << playerImagePath << std::endl;
				return;
			}
			textureCache[playerImagePath] = std::move(texture);
		}

		sf::Sprite playerSprite(textureCache[playerImagePath]);

		playerSprite.setScale(scaleX, scaleY);
		playerSprite.setPosition(static_cast<float>(col * 57), static_cast<float>(row * 57));

		this->window->draw(playerSprite);
	}
}

const bool GameUI::running() const
{
	return this->window->isOpen();
}
