#include "GameUI.h"
#include <iostream>

void GameUI::initVariables()
{
	this->game = new Game();
	game->addGameListener(this);

	if (!this->gameOverTexture.loadFromFile("../../Bomberman/Bomberman.API/Assets/game_over.jpg")) {
		std::cerr << "Failed to load Game Over image!" << std::endl;
	}
	this->gameOverSprite.setTexture(this->gameOverTexture);

	float scaleX = 800.0f / this->gameOverTexture.getSize().x;
	float scaleY = 800.0f / this->gameOverTexture.getSize().y;
	this->gameOverSprite.setScale(scaleX, scaleY);
	this->gameOverSprite.setPosition(0, 0);

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

void GameUI::startNewGame()
{
	delete this->game;
	this->game = new Game();
	game->addGameListener(this);
	game->notifyAllListeners();
}

void GameUI::OnKeyPressed(float elapsedTime)
{
	this->game->HandleExplosion(elapsedTime);
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
			if (this->ev.key.code == sf::Keyboard::Escape) {
				this->window->close();
			}
			else if (this->game->isOver()) {
				// If in Game Over mode
				if (this->ev.key.code == sf::Keyboard::R) {
					startNewGame(); // Restart the game
				}
			}
			else {
				// If in normal game mode
				/*if (this->ev.key.code == sf::Keyboard::F || this->ev.key.code == sf::Keyboard::N) {
					this->game->SetGameOver();
				}*/
				if (this->ev.key.code == sf::Keyboard::N)
				{
					this->game->PlaceBomb(this->game->GetPlayer2());
				}
				if (this->ev.key.code == sf::Keyboard::F)
				{
					this->game->PlaceBomb(this->game->GetPlayer1());
				}
				if (this->ev.key.code == sf::Keyboard::W)
				{
					this->game->MovePlayer(this->game->GetPlayer1(), EPlayerMovementType::Up);
				}
				else if (this->ev.key.code == sf::Keyboard::A)
				{
					this->game->MovePlayer(this->game->GetPlayer1(), EPlayerMovementType::Left);
				}
				else if (this->ev.key.code == sf::Keyboard::S)
				{
					this->game->MovePlayer(this->game->GetPlayer1(), EPlayerMovementType::Down);
				}
				else if (this->ev.key.code == sf::Keyboard::D)
				{
					this->game->MovePlayer(this->game->GetPlayer1(), EPlayerMovementType::Right);
				}
				if (this->ev.key.code == sf::Keyboard::Up)
				{
					this->game->MovePlayer(this->game->GetPlayer2(), EPlayerMovementType::Up);
				}
				if (this->ev.key.code == sf::Keyboard::Left)
				{
					this->game->MovePlayer(this->game->GetPlayer2(), EPlayerMovementType::Left);
				}
				if (this->ev.key.code == sf::Keyboard::Right)
				{
					this->game->MovePlayer(this->game->GetPlayer2(), EPlayerMovementType::Right);
				}
				if (this->ev.key.code == sf::Keyboard::Down)
				{
					this->game->MovePlayer(this->game->GetPlayer2(), EPlayerMovementType::Down);
				}
			}
			break;
		}
	}
}


void GameUI::render()
{
	this->window->clear();
	if (!this->game->isOver()) {
		const auto& board = this->game->getMap()->getBoard();
		for (const auto& row : board) {
			for (const auto* square : row) {
				if (square) {
					renderSquare(square);
				}
			}
		}
	}
	else {
		this->window->draw(this->gameOverSprite);
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
	IBomb* bomb = square->GetBomb();
	if (bomb)
	{
		std::string bombImagePath = bomb->GetImagePath();
		if (textureCache.find(bombImagePath) == textureCache.end()) {
			sf::Texture texture;
			if (!texture.loadFromFile(bombImagePath)) {
				std::cerr << "Failed to load texture: " << bombImagePath << std::endl;
				return;
			}
			textureCache[bombImagePath] = std::move(texture);
		}
		sf::Sprite bombSprite(textureCache[bombImagePath]);
		bombSprite.setScale(scaleX, scaleY);
		bombSprite.setPosition(static_cast<float>(col * 57), static_cast<float>(row * 57));
		this->window->draw(bombSprite);

	}
}

const bool GameUI::running() const
{
	return this->window->isOpen();
}

void GameUI::OnKeyPressed()
{
	this->render();
}
