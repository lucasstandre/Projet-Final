#include <SFML/Graphics.hpp>
#include <iostream>
#include "Terrain.h"


Terrain::Terrain()
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

Terrain::~Terrain()
{


}

sf::RectangleShape& Terrain::ShowTerrain()
{

    return _background;

}

sf::RectangleShape& Terrain::ShowG()
{
    _G.setSize(sf::Vector2f(189, 29));
    _G.setPosition(1300, 3);

    _GTexture.loadFromFile("Gold.png");
    if (_GTexture.loadFromFile("Gold.png"))
    {

    }
    _G.setTexture(&_GTexture);
    return _G;
    // TODO: insérer une instruction return ici
}
