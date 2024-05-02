#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

class Terain 
{
private:
	sf::RectangleShape _background;
	public:
	Terain();
	~Terain();
	sf::RectangleShape& ShowTerain();


};

