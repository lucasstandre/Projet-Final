#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "Terain.h"
#include "Character.h"
#include "PC.h"
#include "ShopKeeper.h"
using namespace std::this_thread;

using namespace sf;
using namespace std;

int main() {
   // Clock clock;
   // Time time;
   // // Création de la fenêtre
   // RenderWindow window(VideoMode(1489, 823), "La valley des poison");
   // window.setFramerateLimit(60);
   // Terain terain; //sf::RectangleShape background(sf::Vector2f(1489, 823));
   // sf::RectangleShape willy(sf::Vector2f(54.4, 102));
   // sf::RectangleShape stick(sf::Vector2f(54.4, 102));
   // sf::Texture texture;
   // if (!texture.loadFromFile("beach.jpg")) {
   //     std::cout << "Error loading texture" << std::endl;
   // }
   // texture.loadFromFile("beach.jpg");
   // background.setTexture(&texture);
   // Texture willyTexture;
   // if (!willyTexture.loadFromFile("willy.png")) {
   //     std::cout << "Error loading texture" << std::endl;
   // }
   // willyTexture.loadFromFile("willy.png");
   // willy.setTexture(&willyTexture);
   // IntRect rectSourceSprite(0, 0, 15, 32);
   // IntRect rectSourceStick(0, 0, 15, 32);
   // stick.setTexture(&willyTexture);
   // stick.setTextureRect(rectSourceStick);
   // willy.setTextureRect(rectSourceSprite);
   // // Boucle principale
   // willy.setPosition(585, 485);
   // bool isPKeyPressed = false;
   // auto startTime = chrono::steady_clock::now();
   // stick.setPosition(-100, -100);
   // while (window.isOpen()) {
   //     // Gestion des événements

   //     Event event;
   //     while (window.pollEvent(event)) {
   //         
   //         if (event.type == Event::Closed) {
   //             window.close();
   //         }
			//else if (event.type == Event::KeyPressed) {
			//	switch (event.key.code)
			//	{
			//	case Keyboard::Escape:
			//		window.close();
			//		break;
			//	case Keyboard::Up:
			//		willy.move(0, -20);
			//		rectSourceSprite.top = 65;
			//		rectSourceSprite.left += 16;
			//		if (rectSourceSprite.left >= 45) {
			//			rectSourceSprite.left = 0;
			//		}
			//		willy.setTextureRect(rectSourceSprite);
			//		break;
			//	case Keyboard::Down:
			//		willy.move(0, 20);
			//		rectSourceSprite.top = 0;
			//		rectSourceSprite.left += 16;
			//		if (rectSourceSprite.left >= 45) {
			//			rectSourceSprite.left = 0;
			//		}
			//		willy.setTextureRect(rectSourceSprite);
			//		break;

			//	case Keyboard::Left:
			//		willy.move(-20, 0);
			//		rectSourceSprite.top = 97;
			//		rectSourceSprite.left += 16;
			//		if (rectSourceSprite.left >= 45) {
			//			rectSourceSprite.left = 0;
			//		}
			//		willy.setTextureRect(rectSourceSprite);
			//		break;

			//		Clock clock;
			//		Time time;
			//		// Création de la fenêtre
			//		RenderWindow window(VideoMode(1489, 823), "La valley des poison");
			//		window.setFramerateLimit(60);
			//		sf::RectangleShape background(sf::Vector2f(1489, 823));
			//		sf::RectangleShape willy(sf::Vector2f(54.4, 102));
			//		sf::RectangleShape stick(sf::Vector2f(54.4, 102));
			//		sf::Texture texture;
			//		if (!texture.loadFromFile("beach.jpg")) {
			//			std::cout << "Error loading texture" << std::endl;
			//		}
			//		texture.loadFromFile("beach.jpg");
			//		background.setTexture(&texture);
			//		Texture willyTexture;
			//		if (!willyTexture.loadFromFile("willy.png")) {
			//			std::cout << "Error loading texture" << std::endl;
			//		}
			//		willyTexture.loadFromFile("willy.png");
			//		willy.setTexture(&willyTexture);
			//		IntRect rectSourceSprite(0, 0, 15, 32);
			//		IntRect rectSourceStick(0, 0, 15, 32);
			//		stick.setTexture(&willyTexture);
			//		stick.setTextureRect(rectSourceStick);
			//		willy.setTextureRect(rectSourceSprite);
			//		// Boucle principale
			//		willy.setPosition(585, 485);
			//		bool isPKeyPressed = false;
			//		auto startTime = chrono::steady_clock::now();
			//		stick.setPosition(-100, -100);
			//		while (window.isOpen()) {
			//			// Gestion des événements

			//			Event event;
			//			while (window.pollEvent(event)) {

			//				if (event.type == Event::Closed) {
			//					window.close();
			//				}
			//				else if (event.type == Event::KeyPressed) {
			//					switch (event.key.code)
			//					{
			//					case Keyboard::Escape:
			//						window.close();
			//						break;
			//					case Keyboard::Up:
			//						willy.move(0, -20);
			//						rectSourceSprite.top = 65;
			//						rectSourceSprite.left += 16;
			//						if (rectSourceSprite.left >= 45) {
			//							rectSourceSprite.left = 0;
			//						}
			//						willy.setTextureRect(rectSourceSprite);
			//						break;
			//					case Keyboard::Down:
			//						willy.move(0, 20);
			//						rectSourceSprite.top = 0;
			//						rectSourceSprite.left += 16;
			//						if (rectSourceSprite.left >= 45) {
			//							rectSourceSprite.left = 0;
			//						}
			//						willy.setTextureRect(rectSourceSprite);
			//						break;

			//					case Keyboard::Left:
			//						willy.move(-20, 0);
			//						rectSourceSprite.top = 97;
			//						rectSourceSprite.left += 16;
			//						if (rectSourceSprite.left >= 45) {
			//							rectSourceSprite.left = 0;
			//						}
			//						willy.setTextureRect(rectSourceSprite);
			//						break;

			//					case Keyboard::Right:
			//						willy.move(20, 0);
			//						rectSourceSprite.top = 33;
			//						rectSourceSprite.left += 16;
			//						if (rectSourceSprite.left >= 45) {
			//							rectSourceSprite.left = 0;
			//						}
			//						willy.setTextureRect(rectSourceSprite);
			//						break;
			//					case Keyboard::P:
			//						time = clock.getElapsedTime();
			//						rectSourceSprite.top = 225;

			//						rectSourceSprite.left += 16;
			//						if (rectSourceSprite.left >= 45) {
			//							rectSourceSprite.left = 0;
			//						}

			//						willy.setTextureRect(rectSourceSprite);
			//						break;
			//					case Keyboard::Space:
			//						rectSourceSprite.top = 129;
			//						rectSourceStick.top = 159;
			//						stick.setPosition(willy.getPosition().x, willy.getPosition().y + 70); // a sacre toute les affaire stick dans un autre affaire

			//						willy.setTextureRect(rectSourceSprite);
			//						stick.setTextureRect(rectSourceStick);
			//						sleep_for(chrono::milliseconds(1000));

			//						//while (//peche)
			//						//{
			//						//    
			//						//    if (Keyboard::Space)
			//						//    {
			//						//        break;
			//						//    }
			//						//}
			//						stick.setPosition(-100, -100);
			//						break;


			//						break;
			//					}
			//				}
			//			}
			//			// Effacement de la fenêtre
			//			window.clear();

			//			// Dessin du cercle
			//			window.draw(background);
			//			window.draw(willy);
			//			window.draw(stick);

			//			// Vérification du temps écoulé depuis l'appui sur la touche P


			//			// Affichage du contenu de la fenêtre
			//			window.display();
			//		}

			//		return 0;
				/*}*/
					Terain terain;
					PC willy("willy");
					ShopKeeper pierre("pierre");

					RenderWindow window(VideoMode(1489, 823), "La valley des poisson");
					window.setFramerateLimit(60);
					sf::RectangleShape& backgroundRef = terain.ShowTerain();  // Get reference
					while (window.isOpen()) {
						Event event;
						while (window.pollEvent(event)) {
							if (event.type == Event::Closed) {
								window.close();
							}
							else if (event.type == Event::KeyPressed) {
								willy.move(event);
								
							}
						}

						window.clear();

						window.draw(terain.ShowTerain());  // Draw using the reference
						window.draw(pierre.ShowCharacter());
						window.draw(willy.ShowCharacter());
					
						window.display();
					}
}

				
			