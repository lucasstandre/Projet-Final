#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Terrain 
{
protected:
	sf::RectangleShape _background;
	sf::IntRect _rectSourceSprite; // Rectangle de la texture à afficher
	sf::Texture _backgroundTexture; // Texture du personnage
	sf::Texture _GTexture;
	sf::RectangleShape _G;

	public:
	Terrain();
	~Terrain();
	sf::RectangleShape& ShowTerrain();
	sf::RectangleShape& ShowG();
};

