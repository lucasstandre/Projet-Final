#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Terain 
{
protected:
	sf::RectangleShape _background;
	sf::IntRect _rectSourceSprite; // Rectangle de la texture à afficher
	sf::Texture _backgroundTexture; // Texture du personnage
	sf::Texture _GTexture;
	sf::RectangleShape _G;

	public:
	Terain();
	~Terain();
	sf::RectangleShape& ShowTerain();
	sf::RectangleShape& ShowG();
};

