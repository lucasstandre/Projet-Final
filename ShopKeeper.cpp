#include "ShopKeeper.h"
#include <iostream>
#include <SFML/Graphics.hpp>


ShopKeeper::ShopKeeper(std::string CharacterPng)
{
	setCharacter(CharacterPng);
	_character.setPosition(925, 345);
}

sf::RectangleShape ShopKeeper::shop()
{

		_shopTexture.loadFromFile("shop.png");
		if (_shopTexture.loadFromFile("shop.png"))
		{
			std::cout << "Error loading texture" << std::endl;

		}
		_shop.setTexture(&_shopTexture);
		_shop.setSize(sf::Vector2f(350, 200));

		sf::Text text;
		text.setString("Bienvenu ! Vous pouvez maitenant acheter une ps5 pour seulement 500$!");
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Black);
		text.setPosition(500, 300);

		_shop.setPosition(500, 300);
		_shop.setFillColor(sf::Color::White);
		_shop.setOutlineThickness(5);
		_shop.setOutlineColor(sf::Color::Black);
		return _shop;
	
}

bool ShopKeeper::interact()
{
	switch (switch_on)
	{
	default:
		break;
	}
	return false;
}
