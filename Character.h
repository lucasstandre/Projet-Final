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

public:
	Character();
	~Character();
	void setCharacter(std::string);
	sf::RectangleShape& ShowCharacter();
	float getPositionX();
	float getPositionY();
};
