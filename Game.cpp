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

using namespace std;


void Game::intialize()
{

}

void Game::save(string characterSaveFile)
{
    ofstream monFlux;
    monFlux.open(characterSaveFile);

    if (!monFlux.is_open())
    {
        exit(1);
    }

    / monFlux >> charactor._getMoney; /

}

void Game::showMenu()
{
	//Menu du jeu de pêche stardew valley
		int menuChoice;
		int characterChoice;
		int saveChoice;
		fstream saveFile;


		//RenderWindow window(VideoMode(1489, 823), "La valley des poison");
		//window.setFramerateLimit(60);
		//RectangleShape background(sf::Vector2f(1489, 823));
		//Texture texture;
		//texture.loadFromFile("menuBG.jpeg");
		//background.setTexture(&texture);



		cout << "MENU" << endl << endl << endl << endl;
		cout << "1. load a game" << endl;
		cout << "2. controls" << endl;
		cout << "3. statistics" << endl;
		cout << "4. fish guide" << endl << endl;

		cout << "your choice: ";
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			cout << "Chose your character" << endl;
			cout << "1. Willy           "; //<< willy.getMoney() << "g" << endl;
			cout << "2. Linus           "; // << linus.getMoney() << "g" << endl;
			cout << "3. Pierre          "; //<< pierre.getMoney() << "g" << endl;
			cin >> characterChoice;

			switch (characterChoice)
			{
			case 1:
				cout << "Do you want to :" << endl;
				cout << "1. load the save of Willy" << endl;
				cout << "2. erase the save and play Willy from the start" << endl;
				cin >> saveChoice;

				switch (saveChoice)
				{
				case 1:
					saveFile.open("WillySave.txt", ios::out);//lecture seulement
					saveFile >> Willy.setMoney();
					saveFile.close();
					//load Willy's save

					//PLAY GAME
					break;
				case 2:
					saveFile.open("WillySave.txt", ios::out);//écriture seulement
					saveFile << 0; //reset willy's money
					willy.setMoney(0); //reset willy's money
					//erase willy's save and start game with linus at 0g

					//PLAY GAME
					break;
				default:
					cout << "Invalid choice" << endl;
					break;
				}
				break;

			case 2:
				cout << "Do you want to :" << endl;
				cout << "1. load the save of Linus" << endl;
				cout << "2. erase the save and play Linus from the start" << endl;
				cin >> saveChoice;

				switch (saveChoice)
				{
				case 1:
					saveFile.open("linusSave.txt", ios::out);//lecture seulement
					saveFile >> linus.setMoney();
					saveFile.close();
					//load linus's save

					//PLAY GAME
					break;
				case 2:
					saveFile.open("linusSave.txt", ios::out);//écriture seulement
					saveFile << 0; //reset linus's money
					linus.setMoney(0); //reset linus's money
					//erase linus's save and start game with linus at 0g

					//PLAY GAME
					break;
				default:
					cout << "Invalid choice" << endl;
					break;
				}
				break;

			case 3:
				cout << "Do you want to :" << endl;
				cout << "1. load the save of Pierre" << endl;
				cout << "2. erase the save and play Pierre from the start" << endl;
				cin >> saveChoice;

				switch (saveChoice)
				{
				case 1:
					saveFile.open("PierreSave.txt", ios::out);//lecture seulement
					saveFile >> Pierre.setMoney();
					saveFile.close();
					//load pierre's save
					//PLAY GAME
					break;
				case 2:
					saveFile.open("PierreSave.txt", ios::out);//écriture seulement
					saveFile << 0; //reset Pierre's money
					Pierre.setMoney(0); //reset Pierre's money
					//erase Pierre's save and start game with linus at 0g

					//PLAY GAME
					break;
				default:
					cout << "Invalid choice" << endl;
					break;
				}
				break;
			default:
				cout << "Invalid choice" << endl;
				break;
			}

			break;

		case 2:
			cout << "Controls" << endl << endl;
			cout << "To cast your line, press the space bar" << endl;
			cout << "To move your character, use the arrow keys" << endl;
			cout << "To leave the game, press the escape key" << endl;
			break;
			//display the controls of the game with an image of the keyboard (can't do it until i have all the contrôls)

		case 3:
			cout << "Statistics" << endl << endl;
			cout << "Willy has " << "g" << endl; //get the gold of willy
			cout << "Linus has " << "g" << endl; //get the gold of linus
			cout << "Pierre has " << "g" << endl; //get the gold of pierre
			break;

		case 4:
			cout << "here is the fish guide" << endl;
			//display the fish guide

		default:
			cout << "Invalid choice" << endl;
			break;
		}



		system("pause");
	}
}

void Game::miniGame()
{
    //fish.selectRandomFish();

}