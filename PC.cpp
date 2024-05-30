#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include <string>
#include "Character.h"
#include"Game.h"
#include "PC.h"
#include"miniGame.h"

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace sf;
using namespace std;
PC::PC()
{
	setCharacter("willy");
	_character.setPosition(585, 485);
    _money = 0;
	_Lvl = 1;
}
PC::PC(std::string CharacterPng)
{
    setCharacter(CharacterPng);
    _character.setPosition(585, 485);
    _money = 0;
    _Lvl = 1;
}
int PC::getMoney() const
{
    return _money;
}

int PC::getLvl() const
{
	return _Lvl;
}

int PC::getPS5() const
{
	return _PS5;
}

void PC::setMoney(int money)
{
	_money =+ money;
}

void PC::setLvl(bool lvl)
{
		_Lvl =+ lvl;
}

void PC::setPS5(int PS5)
{
	_PS5 =+ PS5;
}

void PC::moveUp()
{
	if (_character.getPosition().y > -75 && _character.getPosition().x <= 395 || _character.getPosition().x >= 385 && _character.getPosition().y >= 385){
	_character.move(0, -10);
	_rectSourceSprite.top = 65;
	_rectSourceSprite.left += 16;
	if (_rectSourceSprite.left >= 45) {
		_rectSourceSprite.left = 0;
	}
	_character.setTextureRect(_rectSourceSprite);
	}
}

void PC::moveDown()
{
	if (_character.getPosition().y < 485) {
		_character.move(0, 10);
		_rectSourceSprite.top = 0;
		_rectSourceSprite.left += 16;
		if (_rectSourceSprite.left >= 45) {
			_rectSourceSprite.left = 0;
		}
		_character.setTextureRect(_rectSourceSprite);
	}
}

void PC::moveRight()
{
	if (_character.getPosition().x < 1205 && _character.getPosition().y >= 375 || _character.getPosition().y <= 385 && _character.getPosition().x <= 385) {
			_character.move(10, 0);
			_rectSourceSprite.top = 33;
			_rectSourceSprite.left += 16;
			if (_rectSourceSprite.left >= 45) {
				_rectSourceSprite.left = 0;
			}
			_character.setTextureRect(_rectSourceSprite);
	}
}

void PC::moveLeft()
{
	if (_character.getPosition().x > 225) {
		_character.move(-10, 0);
		_rectSourceSprite.top = 97;
		_rectSourceSprite.left += 16;
		if (_rectSourceSprite.left >= 45) {
			_rectSourceSprite.left = 0;
		}
		_character.setTextureRect(_rectSourceSprite);
	}
}

void PC::animation()
{
	_rectSourceSprite.top = 225;

	_rectSourceSprite.left += 16;
	if (_rectSourceSprite.left >= 45) {
		_rectSourceSprite.left = 0;
	}

	_character.setTextureRect(_rectSourceSprite);
}

void PC::space()
{

	_rectSourceSprite.top = 129;
	//_rectSourceStick.top = 159;
	//stick.setPosition(_character.getPosition().x, _character.getPosition().y + 70); // a sacre toute les affaire stick dans un autre affaire

	_character.setTextureRect(_rectSourceSprite);
	//stick.setTextureRect(rectSourceStick);
	/*sleep_for(chrono::milliseconds(1000));*/
	
	MiniGame miniGame;
	//miniGame.play(getLvl(), getPositionX(), getPositionY());
	//while (//peche)
	//{
	//    
	//    if (Keyboard::Space)
	//    {
	//        break;
	//    }
	//}
}

sf::Text &PC::showMoney()
{
	_text.setString(std::to_string(_money));
	_text.setCharacterSize(30);
	_font.loadFromFile("Stardew_Valley.ttf");

	if (!_font.loadFromFile("Stardew_Valley.ttf"))
	{
		cout << "erreur de police!";
	}
	_text.setFont(_font);
	_text.setFillColor(sf::Color(165,42,42));
	_text.setPosition(1405,2 );
	return _text;

}

void PC::buyPS5()
{

	
		_money -= 500;
		_PS5 += 1;

}






