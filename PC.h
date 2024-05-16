#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include"Game.h"
#include "PC.h"


class PC : public Character
{
protected:

	int _money;
	int _Lvl;
	public:
		PC();
		PC(std::string);
	int getMoney() const;
	int getLvl() const;
	void setMoney(int money);
	void setLvl(int lvl);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void animation();
	void space();
	void limit();


};

