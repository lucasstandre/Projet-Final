#include "Fish.h"

using namespace std;
using namespace sf;

void Fish::setName(std::string name)
{
	assert(name != "");
	_name.setString(name);
	_name.setPosition(sf::Vector2f(450, 600));

	_textFont.loadFromFile("Stardew_Valley.ttf");

	if (!_textFont.loadFromFile("Stardew_Valley.ttf"))
	{
		cout << "erreur de police!";
	}
	_name.setFillColor(sf::Color::Black);


	_name.setFont(_textFont);
	_name.setCharacterSize(40);
}

void Fish::setGoldValue(int gold)
{
	assert(gold > 0);
	_goldValue = gold;
}

void Fish::setExpReceived(double exp)
{
	assert(exp > 0);
	_expReceived = exp;
}

void Fish::setFishTexture(std::string nameFile)
{
	_fishTexture.loadFromFile(nameFile);

	if (!_fishTexture.loadFromFile(nameFile))
	{
		cout << "erreur dans la texture du poisson!";
	}
	_fish.setTexture(&_fishTexture);

}

void Fish::setFishTexture(sf::Texture& fishTexture){
	_fishTexture = fishTexture;
	_fish.setTexture(&fishTexture);

}
int Fish::getGoldValue()
{
	return _goldValue;
}

int Fish::getExpReceived()
{
	return _expReceived;
}

sf::Texture& Fish::getFishTexture()//
{
	return _fishTexture;
}

sf::RectangleShape& Fish::displayWindow()
{
	_DisplayWindow.setPosition(sf::Vector2f(425, 350));
	_DisplayWindow.setSize(sf::Vector2f(638, 360));


	_DisplayWindowTexture.loadFromFile("DisplayFish.png");

	if (!_DisplayWindowTexture.loadFromFile("DisplayFish.png"))
	{
		cout << "erreur dans la texture";
	}
	_DisplayWindow.setTexture(&_DisplayWindowTexture);

	return _DisplayWindow;
}

sf::Text& Fish::getName()
{
		return _name;

}
sf::Text& Fish::displayTextFish()
{
	return _name;
}
sf::RectangleShape& Fish::displayFish(){

	_fish.setPosition(sf::Vector2f(625, 400));
	_fish.setSize(sf::Vector2f(200, 200));
	return _fish;
}



