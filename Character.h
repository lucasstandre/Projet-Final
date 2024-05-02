#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class Character
{
protected:
	sf::IntRect _rectSourceSprite; // Rectangle de la texture à afficher
	sf::RectangleShape _character; // Rectangle du personnage
	sf::Texture _characterTexture; // Texture du personnage
	sf::Vector2f _position; // Position du personnage

	public:
	Character(std::string);
	~Character();
	float getPositionX();
	float getPositionY();
	void setPosition(float x, float y);

};

