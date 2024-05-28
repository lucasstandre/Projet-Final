#include "ShopKeeper.h"
#include <iostream>
#include <SFML/Graphics.hpp>


ShopKeeper::ShopKeeper()
{
	setCharacter("pierre");
	_character.setPosition(925, 345);
}

sf::RectangleShape ShopKeeper::shop()
{

		_shopTexture.loadFromFile("DisplayFish.png");
		if (_shopTexture.loadFromFile("DisplayFish.png"))
		{
			std::cout << "Error loading texture" << std::endl;

		}
		_shop.setTexture(&_shopTexture);
		_shop.setSize(sf::Vector2f(350, 200));
		_shop.setPosition(500, 300);
		_shop.setFillColor(sf::Color::White);
		_shop.setOutlineThickness(5);
		_shop.setOutlineColor(sf::Color::Black);
		return _shop;
	
}

sf::Text ShopKeeper::interact()
{
	_text.setString("Bienvenu ! Vous pouvez maitenant acheter une ps5 pour seulement 500$!");
	_text.setCharacterSize(24);
	_text.setFillColor(sf::Color::Black);
	_text.setPosition(500, 300);
	return _text;
}
