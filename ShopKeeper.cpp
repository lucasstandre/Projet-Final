#include "ShopKeeper.h"
#include <iostream>
#include <SFML/Graphics.hpp>


ShopKeeper::ShopKeeper()
{
	setCharacter("pierre");
	_character.setPosition(925, 345);
    if (!_font.loadFromFile("Stardew_Valley.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    _text.setFont(_font);
    _text.setCharacterSize(40);
    _text.setFillColor(sf::Color::White);
    _text.setPosition(220, 390);

    if (!_shopTexture.loadFromFile("talkingPierre.png")) {
        std::cout << "Error loading texture pierre shop" << std::endl;
    }
    _shopSprite.setTexture(_shopTexture);
    _shopSprite.setPosition(200, 350);
}

void ShopKeeper::setShop()
{
	_text.setString("\nAppuyer sur 1 pour acheter une ps5 a 500g \nAppuyer sur 2 pour quitter");

}
void ShopKeeper::setText(const std::string& text) {
	_text.setString(text);
}
sf::Text& ShopKeeper::getText() {
	return _text;
}
sf::Sprite& ShopKeeper::getShop() {
	return _shopSprite;
}
void ShopKeeper::drawShop(sf::RenderWindow& window) {
  
    window.draw(_shopSprite);
    window.draw(_text);
}