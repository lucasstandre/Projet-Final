#include "Character.h"
#include"Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
Character::Character(std::string CharacterPng)
{
_character.setSize(sf::Vector2f(54.4, 102)); // Taille du personnage

_characterTexture.loadFromFile(CharacterPng+".png"); // Chargement de la texture du personnage
if (_characterTexture.loadFromFile(CharacterPng+".png"))
{

}
_character.setTexture(&_characterTexture);

_rectSourceSprite = sf::IntRect(0, 0, 15, 32);

_character.setTextureRect(_rectSourceSprite);

}

Character::~Character()
{
	_characterTexture.~Texture();
	_character.~RectangleShape();
	//_rectSourceSprite.~IntRect();
}
