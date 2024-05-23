#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include "Game.h"
#include "Character.h"
#include "Fish.h"
#include "FishingRod.h"
#include "NPC.h"
#include "ShopKeeper.h"
#include "Terain.h"
#include "PC.h"

using namespace sf;
using namespace std;

void Game::save(string characterSaveFile, int moneyPC)
{
    fstream monFlux;
    monFlux.open(characterSaveFile);

    if (!monFlux.is_open())
    {
        exit(1);
    }

    monFlux >> moneyPC;
    monFlux.close();

}

void Game::showMenu(sf::RenderWindow& window)
{
    // Menu setup
    fstream saveFile;
    RectangleShape menu(Vector2f(1489, 823));
    Texture texturemenu;
    texturemenu.loadFromFile("Menu1.jpg");
    menu.setTexture(&texturemenu);

    window.clear();
    window.draw(menu);
    window.display();

    int moneyWilly=0;
    int moneyPrettyWilly=0;
    int moneyEmoWilly=0;

    PC Willy("Willy");
    PC prettyWilly("Pretty Willy");
    PC emoWilly("Emo Willy");

    saveFile.open("WillySave.txt", ios::in);
    if (saveFile.is_open()) {
        saveFile >> moneyWilly;
        saveFile.close();
    }

    saveFile.open("PrettyWillySave.txt", ios::in);
    if (saveFile.is_open()) {
        saveFile >> moneyPrettyWilly;
        saveFile.close();
    }

    saveFile.open("EmoWillySave.txt", ios::in);
    if (saveFile.is_open()) {
        saveFile >> moneyEmoWilly;
        saveFile.close();
    }

    Willy.setMoney(moneyWilly);
    prettyWilly.setMoney(moneyPrettyWilly);
    emoWilly.setMoney(moneyEmoWilly);

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case Keyboard::Num1:
                    texturemenu.loadFromFile("Willychoicemenu.jpg");
                    menu.setTexture(&texturemenu);
                    window.clear();
                    window.draw(menu);
                    window.display();

                    while (true)
                    {
                        if (window.pollEvent(event))
                        {
                            if (event.type == sf::Event::Closed)
                            {
                                window.close();
                                return;
                            }
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                            {
                                window.clear();
                                texturemenu.loadFromFile("Menu1.jpg");
                                menu.setTexture(&texturemenu);
                                window.draw(menu);
                                window.display();
                                break;  // Exit the submenu
                            }

                            if (event.type == sf::Event::KeyPressed)
                            {
                                switch (event.key.code)
                                {
                                case Keyboard::Num1:
                                    texturemenu.loadFromFile("Willymenu.jpg");
                                    menu.setTexture(&texturemenu);
                                    window.clear();
                                    window.draw(menu);
                                    window.display();

                                    while (true)
                                    {
                                        if (window.pollEvent(event))
                                        {
                                            if (event.type == sf::Event::Closed)
                                            {
                                                window.close();
                                                return;
                                            }
                                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                                            {
                                                texturemenu.loadFromFile("Menu1.jpg");
                                                menu.setTexture(&texturemenu);
                                                break;  // Exit the submenu
                                            }

                                            if (event.type == sf::Event::KeyPressed)
                                            {
                                                switch (event.key.code)
                                                {
                                                case Keyboard::Num1:
                                                    // Play the game
                                                    // play();
                                                    break;
                                                case Keyboard::Num2:
                                                    moneyWilly = 0; // reset Willy's money
                                                    Willy.setMoney(0); // reset Willy's money
                                                    // Play the game
                                                    // play();
                                                    break;
                                                case Keyboard::Escape:
                                                    texturemenu.loadFromFile("Menu1.jpg");
                                                    menu.setTexture(&texturemenu);
                                                    window.clear();
                                                    window.draw(menu);
                                                    window.display();
                                                   break;
                                                default:
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    break;

                                case Keyboard::Num2:
                                    texturemenu.loadFromFile("Prettywillymenu.jpg");
                                    menu.setTexture(&texturemenu);
                                    window.clear();
                                    window.draw(menu);
                                    window.display();

                                    while (true)
                                    {
                                        if (window.pollEvent(event))
                                        {
                                            if (event.type == sf::Event::Closed)
                                            {
                                                window.close();
                                                return;
                                            }
                                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                                            {
                                                break;  // Exit the submenu
                                            }

                                            if (event.type == sf::Event::KeyPressed)
                                            {
                                                switch (event.key.code)
                                                {
                                                case Keyboard::Num1:
                                                    // Play the game
                                                    // play();
                                                    break;
                                                case Keyboard::Num2:
                                                    moneyPrettyWilly = 0; // reset Pretty Willy's money
                                                    prettyWilly.setMoney(0); // reset Pretty Willy's money
                                                    // Play the game
                                                    // play();
                                                    break;
                                                default:
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    break;

                                case Keyboard::Num3:
                                    texturemenu.loadFromFile("emoWillyMenu.jpg");
                                    menu.setTexture(&texturemenu);
                                    window.clear();
                                    window.draw(menu);
                                    window.display();

                                    while (true)
                                    {
                                        if (window.pollEvent(event))
                                        {
                                            if (event.type == sf::Event::Closed)
                                            {
                                                window.close();
                                                return;
                                            }
                                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                                            {
                                                window.clear();
                                                texturemenu.loadFromFile("Menu1.jpg");
                                                menu.setTexture(&texturemenu);
                                                window.draw(menu);
                                                window.display();
                                                break;  // Exit the submenu
                                            }

                                            if (event.type == sf::Event::KeyPressed)
                                            {
                                                switch (event.key.code)
                                                {
                                                case Keyboard::Num1:
                                                    // Play the game
                                                    // play();
                                                    break;
                                                case Keyboard::Num2:
                                                    moneyEmoWilly = 0; // reset Emo Willy's money
                                                    emoWilly.setMoney(0); // reset Emo Willy's money
                                                    // Play the game
                                                    // play();
                                                    break;
                                                default:
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    break;

                                default:
                                    break;
                                }
                            }
                        }
                    }
                    break;

                case Keyboard::Num2:
                    texturemenu.loadFromFile("controls_menu.jpg");
                    menu.setTexture(&texturemenu);
                    window.clear();
                    window.draw(menu);
                    window.display();

                    while (true)
                    {
                        if (window.pollEvent(event))
                        {
                            if (event.type == sf::Event::Closed)
                            {
                                window.close();
                                return;
                            }
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                            {
                                window.clear();
                                texturemenu.loadFromFile("Menu1.jpg");
                                menu.setTexture(&texturemenu);
                                window.draw(menu);
                                window.display();
                                break;  // Exit the submenu
                            }
                        }
                    }
                    break;

                case Keyboard::Num3:
                    std::cout << "Statistics" << std::endl << std::endl;
                    std::cout << "Willy has " << moneyWilly << "g" << std::endl;
                    std::cout << "Pretty Willy has " << moneyPrettyWilly << "g" << std::endl;
                    std::cout << "Emo Willy has " << moneyEmoWilly << "g" << std::endl;
                    break;

                case Keyboard::Num4:
                    texturemenu.loadFromFile("fishGuide.jpg");
                    menu.setTexture(&texturemenu);
                    window.clear();
                    window.draw(menu);
                    window.display();

                    while (true)
                    {
                        if (window.pollEvent(event))
                        {
                            if (event.type == sf::Event::Closed)
                            {
                                window.close();
                                return;
                            }
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                            {
                              
                                window.clear();
                                texturemenu.loadFromFile("Menu1.jpg");
                                menu.setTexture(&texturemenu);
                                window.draw(menu);
                                window.display();

                                break;  // Exit the submenu
                            }
                        }
                    }
                    break;

                default:
                    break;
                }
            }
        }
    }
}
