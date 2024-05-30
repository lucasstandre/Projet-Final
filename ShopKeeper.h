#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Character.h"
class ShopKeeper : public Character
{
protected:
		sf::Sprite _shopSprite;
		sf::Texture _shopTexture; 
		sf::Text _text;
		sf::Font _font;
public:
	ShopKeeper();
	void setShop();
	void setText(const std::string& text);
	sf::Text& getText();
	sf::Sprite& getShop();
	void drawShop(sf::RenderWindow& window);
};

