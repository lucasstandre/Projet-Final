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


//Game::Game()
//{
//
//}
//
//void Game::intialize()
//{
//
//}

void Game::save(string characterSaveFile)
{
    ofstream monFlux;
    monFlux.open(characterSaveFile);

    if (!monFlux.is_open())
    {
        exit(1);
    }

}

void Game::showMenu(sf::Event event)
{
	//Menu du jeu de pêche stardew valley
		fstream saveFile;


		Window window(VideoMode(1489, 823), "Menu");
		RectangleShape menu(sf::Vector2f(1489, 823));
		Texture texturemenu;
		texturemenu.loadFromFile("willy.png");
		menu.setTexture(&texturemenu);

		int moneyWilly;
		int moneyLinus;
		int moneyPierre;

		PC Willy("Willy");
		PC Linus("Linux");
		PC Pierre("Pierre");

		saveFile.open("WillySave.txt", ios::out);
		saveFile >> moneyWilly;
		saveFile.close();

		saveFile.open("LinusSave.txt", ios::out);
		saveFile >> moneyLinus;
		saveFile.close();

		saveFile.open("PierreSave.txt", ios::out);
		saveFile >> moneyPierre;
		saveFile.close();

		Willy.setMoney(moneyWilly);
		Linus.setMoney(moneyLinus);
		Pierre.setMoney(moneyLinus);

		

		/*cout << "MENU" << endl << endl << endl << endl;
		cout << "1. load a game" << endl;
		cout << "2. controls" << endl;
		cout << "3. statistics" << endl;
		cout << "4. fish guide" << endl << endl;

		cout << "your choice: ";*/
		

		switch (event.key.code)
		{
		case Keyboard::Num1:
			//cout << "Chose your character" << endl;
			//cout << "1. Willy           "; //<< willy.getMoney() << "g" << endl;
			//cout << "2. Linus           "; // << linus.getMoney() << "g" << endl;
			//cout << "3. Pierre          "; //<< pierre.getMoney() << "g" << endl;
			//

			switch (event.key.code)
			{
			case Keyboard::Num1:
				/*cout << "Do you want to :" << endl;
				cout << "1. load the save of Willy" << endl;
				cout << "2. erase the save and play Willy from the start" << endl;*/

				switch (event.key.code)
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																			
				{
				case 1:
					
						
					

					//PLAY GAME
					break;
				case 2:
					
					moneyWilly = 0;//reset willy's money
					Willy.setMoney(0); //reset willy's money
					//erase willy's save and start game with willy at 0g

					//PLAY GAME
					break;
				default:
					break;
				}
				break;

			case Keyboard::Num2:
				/*cout << "Do you want to :" << endl;
				cout << "1. load the save of Linus" << endl;
				cout << "2. erase the save and play Linus from the start" << endl;*/

				switch (event.key.code)
				{
				case Keyboard::Num1:
					

					//PLAY GAME

					break;

				case Keyboard::Num2:
					
					moneyLinus = 0; //reset linus's money
					Linus.setMoney(0); //reset linus's money
					//erase linus's save and start game with linus at 0g

					//PLAY GAME
					break;

				default:
					break;
				}
				break;

			case Keyboard::Num3:
				/*cout << "Do you want to :" << endl;
				cout << "1. load the save of Pierre" << endl;
				cout << "2. erase the save and play Pierre from the start" << endl;*/
				

				switch (event.key.code)
				{
				case  Keyboard::Num1:
					
					//PLAY GAME

					break;
				case Keyboard::Num3:
					
					moneyPierre = 0; //reset Pierre's money
					Pierre.setMoney(0); //reset Pierre's money
					//erase Pierre's save and start game with linus at 0g

					//PLAY GAME
					break;
				default:
					 
					break;
				}
				break;
			default:
				break;
			}

			break;

		case Keyboard::Num2:
			texturemenu.loadFromFile("controlsMenu.jpeg");
			menu.setTexture(&texturemenu);
			break;
			//display the controls of the game with an image of the keyboard (can't do it until i have all the contrôls)

		case Keyboard::Num3:
			std::cout << "Statistics" << endl << endl;
			std::cout << "Willy has " << moneyWilly << "g" << endl; //get the gold of willy
			std::cout << "Linus has " << moneyLinus <<"g" << endl; //get the gold of linus
			std::cout << "Pierre has " << moneyPierre << "g" << endl; //get the gold of pierre
			break;

		case Keyboard::Num4:
			texturemenu.loadFromFile("fishGuide.jpeg");
			menu.setTexture(&texturemenu);
			//display the fish guide

		default:
			
			break;
		}



		system("pause");
	}

//
//void Game::miniGame()
//{
//    //fish.selectRandomFish();
//
//}