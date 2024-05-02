#pragma once
#include <SFML/Graphics.hpp>

class Terain
{
	private:
		sf::RectangleShape _background;
	public:
	Terain();
	~Terain();
	sf::RectangleShape ShowTerain();
};

