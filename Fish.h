#include"SFML/Graphics.hpp"
#include <iostream>
#include <cassert>

#pragma once
class Fish
{
protected:
	int _goldValue;
	int _expReceived;

	sf::RectangleShape _fish;
	sf::RectangleShape _DisplayWindow;
	sf::Font _textFont;
	sf::Text _name;
	sf::Texture _fishTexture;
	sf::Texture _DisplayWindowTexture;

public:

	void setGoldValue(int gold);
	void setExpReceived(int exp);
	void setFishTexture(std::string nameFile);
	void setFishTexture(sf::Texture& _fishTexture);
	void setName(std::string name);

	int getGoldValue();
	int getExpReceived();
	sf::Texture& getFishTexture();
	sf::Text& getName();

	sf::RectangleShape& displayWindow();
	sf::RectangleShape& displayFish();
	sf::Text& displayTextFish();
	

	
	//~Fish();
};

