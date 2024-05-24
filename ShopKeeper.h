#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Character.h"
class ShopKeeper : public Character
{
protected:
		sf::RectangleShape _shop;
		sf::Texture _shopTexture; 
public:
	ShopKeeper();
	sf::RectangleShape shop();
	bool interact();
};

