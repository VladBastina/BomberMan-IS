#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Bomberman");
}

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::update()
{
	this->pollEvents();

}

void Game::pollEvents()
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

void Game::render()
{
	/*
		return void:
		- clear 


		Renders the game objects
	
	*/
	this->window->clear(sf::Color(255, 0, 0, 0));

	// Draw game objects

	this->window->display();
}

const bool Game::running() const
{
	return this->window->isOpen();
}
