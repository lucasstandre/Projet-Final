#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include"Game.h"

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace sf;
using namespace std;
Character::Character()
{
}

Character::~Character()
{
	//_characterTexture.~Texture();
	//_character.~RectangleShape();
	//_rectSourceSprite.~IntRect();
}

void Character::setCharacter(std::string CharacterPng)
{
	_character.setSize(sf::Vector2f(54.4, 102)); // Taille du personnage

	_characterTexture.loadFromFile(CharacterPng + ".png"); // Chargement de la texture du personnage
	if (_characterTexture.loadFromFile(CharacterPng + ".png"))
	{
		std::cout << "Error loading texture" << std::endl;

	}
	_character.setTexture(&_characterTexture);

	_rectSourceSprite = sf::IntRect(0, 0, 15, 32);

	_character.setTextureRect(_rectSourceSprite);
	

}

float Character::getPositionX()
{
    return _character.getPosition().x;
}
float Character::getPositionY()
{
	return _character.getPosition().y;
}

sf::Texture& Character::getTexture()
{
	return _characterTexture;
}






sf::RectangleShape& Character::ShowCharacter()
{
	return _character;
}

