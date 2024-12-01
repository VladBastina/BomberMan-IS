#pragma once
#include <SFML/Graphics.hpp>

static class TextureHandler
{
public:
	sf::Texture GenerateTexture(const std::string& filePath);
	sf::Sprite GenerateSprite(const std::string& filePath);
	//sf::Sprite
	void SetScale();

};

