#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Character.h"
class ShopKeeper : public Character
{
protected:
		sf::RectangleShape _shop;
		sf::Texture _shopTexture; 
		sf::Text _text;
public:
	ShopKeeper();
	sf::RectangleShape shop();
	sf::Text interact();
};

