#include "Terain.h"
#include <SFML/Graphics.hpp>
#include <iostream>



Terain::Terain()
{
	_background.setSize(sf::Vector2f(1489, 823));
    sf::Texture texture;
    if (!texture.loadFromFile("beach.jpg")) {
        std::cout << "Error loading texture" << std::endl;
    }
    texture.loadFromFile("beach.jpg");
    _background.setTexture(&texture);


}

Terain::~Terain()
{
}

sf::RectangleShape Terain::ShowTerain()
{
    sf::RectangleShape background(sf::Vector2f(1489, 823));
    sf::Texture texture;
    if (!texture.loadFromFile("beach.jpg")) {
        std::cout << "Error loading texture" << std::endl;
    }
    texture.loadFromFile("beach.jpg");
    background.setTexture(&texture);
    return background;

}
