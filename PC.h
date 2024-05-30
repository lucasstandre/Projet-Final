#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "PC.h"


class PC : public Character
{
protected:
	int _PS5;
	int _money;
	double _Lvl = 0;
	sf::Text _text;
	sf::Font _font;

	public:

		PC();
		PC(std::string);

	int getMoney() const;
	int getLvl() const;
	int getPS5() const;

	void setMoney(int money);
	void setLvl(bool lvl);
	void setPS5(int PS5);

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void animation();
	void space();
	sf::Text &showMoney();
	void buyPS5();



};

