#include <SFML/Graphics.hpp>
#include <iostream>
#include "Terain.h"


Terain::Terain()
{
	
    sf::Texture texture;
    if (!texture.loadFromFile("beach1.png")) {
        std::cout << "Error loading texture" << std::endl;
    }
    texture.loadFromFile("beach1.png");
        _background.setSize(sf::Vector2f(1489, 823));
        _background.setTexture(&texture);
}

Terain::~Terain()
{


}

sf::RectangleShape& Terain::ShowTerain()
{

    return _background;


}
