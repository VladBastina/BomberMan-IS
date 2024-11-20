#include "GameUI.h"

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
	/*
		return void:
		- clear 


		Renders the GameUI objects
	
	*/
	this->window->clear(sf::Color(255, 0, 0, 0));

	// Draw GameUI objects

	this->window->display();
}

const bool GameUI::running() const
{
	return this->window->isOpen();
}
