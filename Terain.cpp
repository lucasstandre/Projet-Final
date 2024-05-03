#include <SFML/Graphics.hpp>
#include <iostream>
#include "Terain.h"


Terain::Terain()
{
    _background.setSize(sf::Vector2f(1489, 823)); // Taille du personnage

    _backgroundTexture.loadFromFile("beach.jpg"); // Chargement de la texture du personnage
    if (_backgroundTexture.loadFromFile("beach.jpg"))
    {

    }
    _background.setTexture(&_backgroundTexture);

    //_rectSourceSprite = sf::IntRect(0, 0, 15, 32);

    //_background.setTextureRect(_rectSourceSprite);

  
    
    //sf::Texture texture;
    //if (!texture.loadFromFile("beach.jpg")) {
    //    std::cout << "Error loading texture" << std::endl;
    //}
    //texture.loadFromFile("beach.jpg");
    //    _background.setSize(sf::Vector2f(1489, 823));
    //    _background.setTexture(&texture);
}

Terain::~Terain()
{


}

sf::RectangleShape& Terain::ShowTerain()
{

    return _background;

}
