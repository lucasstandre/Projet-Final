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

void PC::setMoney(int money)
{
	_money = money;
}

void PC::setLvl(int lvl)
{
		_Lvl = lvl;
}

void PC::move(sf::Event event)
{
	switch (event.key.code)
	{
	case Keyboard::Escape:
		/*game.window().close();*/
		break;
	case Keyboard::Up:
		_character.move(0, -20);
		_rectSourceSprite.top = 65;
		_rectSourceSprite.left += 16;
		if (_rectSourceSprite.left >= 45) {
			_rectSourceSprite.left = 0;
		}
		_character.setTextureRect(_rectSourceSprite);
		break;
	case Keyboard::Down:
		_character.move(0, 20);
		_rectSourceSprite.top = 0;
		_rectSourceSprite.left += 16;
		if (_rectSourceSprite.left >= 45) {
			_rectSourceSprite.left = 0;
		}
		_character.setTextureRect(_rectSourceSprite);
		break;

	case Keyboard::Left:
		_character.move(-20, 0);
		_rectSourceSprite.top = 97;
		_rectSourceSprite.left += 16;
		if (_rectSourceSprite.left >= 45) {
			_rectSourceSprite.left = 0;
		}
		_character.setTextureRect(_rectSourceSprite);
		break;

	case Keyboard::Right:
		_character.move(20, 0);
		_rectSourceSprite.top = 33;
		_rectSourceSprite.left += 16;
		if (_rectSourceSprite.left >= 45) {
			_rectSourceSprite.left = 0;
		}
		_character.setTextureRect(_rectSourceSprite);
		break;
	case Keyboard::P:

		_rectSourceSprite.top = 225;

		_rectSourceSprite.left += 16;
		if (_rectSourceSprite.left >= 45) {
			_rectSourceSprite.left = 0;
		}

		_character.setTextureRect(_rectSourceSprite);
		break;
	case Keyboard::Space:
		
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
		break;

	}
}

void PC::limit()
{
	if (_character.getPosition().x > 1205)
	{
		_character.setPosition(_character.getPosition().x - 20, _character.getPosition().y);
	}
	else if (_character.getPosition().x < 225) 
	{
		_character.setPosition(_character.getPosition().x + 20, _character.getPosition().y);
	}
	else if (_character.getPosition().y > 485)
	{
		_character.setPosition(_character.getPosition().x, _character.getPosition().y - 20);
	}
	else if (_character.getPosition().y < -75)
	{
		_character.setPosition(_character.getPosition().x, _character.getPosition().y + 20);
	}
	else if (_character.getPosition().y<=385 && _character.getPosition().x>=385)
	{
		_character.setPosition(_character.getPosition().x, _character.getPosition().y+20);
	}
	else if (_character.getPosition().y<=385 && _character.getPosition().x>=385)
	{
		_character.setPosition(_character.getPosition().x -20, _character.getPosition().y);
	}	
}

