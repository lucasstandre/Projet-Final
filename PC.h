#pragma once
#include "Character.h"

class PC : public Character
{
protected:

	int _money;

	public:
	PC ();
	void move();
	int getMoney();


};

