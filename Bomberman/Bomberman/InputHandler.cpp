#include "InputHandler.h"

void InputHandler::HandleKeyPress(sf::Event& event, IGame* game, sf::RenderWindow* window)
{
    if (event.key.code == sf::Keyboard::Escape) {
        window->close();
    }
    else {
        HandlePlayerMovement(event, game);
        HandleBombPlacement(event, game);
    }
}

void InputHandler::HandlePlayerMovement(sf::Event& event, IGame* game)
{
    if (event.key.code == sf::Keyboard::W) {
        game->MovePlayer(game->GetPlayer1(), EPlayerMovementType::Up);
    }
    else if (event.key.code == sf::Keyboard::A) {
        game->MovePlayer(game->GetPlayer1(), EPlayerMovementType::Left);
    }
    else if (event.key.code == sf::Keyboard::S) {
        game->MovePlayer(game->GetPlayer1(), EPlayerMovementType::Down);
    }
    else if (event.key.code == sf::Keyboard::D) {
        game->MovePlayer(game->GetPlayer1(), EPlayerMovementType::Right);
    }

    if (event.key.code == sf::Keyboard::Up) {
        game->MovePlayer(game->GetPlayer2(), EPlayerMovementType::Up);
    }
    else if (event.key.code == sf::Keyboard::Left) {
        game->MovePlayer(game->GetPlayer2(), EPlayerMovementType::Left);
    }
    else if (event.key.code == sf::Keyboard::Down) {
        game->MovePlayer(game->GetPlayer2(), EPlayerMovementType::Down);
    }
    else if (event.key.code == sf::Keyboard::Right) {
        game->MovePlayer(game->GetPlayer2(), EPlayerMovementType::Right);
    }
}

void InputHandler::HandleBombPlacement(sf::Event& event, IGame* game)
{
    if (event.key.code == sf::Keyboard::N) {
        game->PlaceBomb(game->GetPlayer2());
    }
    else if (event.key.code == sf::Keyboard::F) {
        game->PlaceBomb(game->GetPlayer1());
    }
}
