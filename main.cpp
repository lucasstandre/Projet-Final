#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "Terain.h"
#include "Character.h"
#include "PC.h"
#include "ShopKeeper.h"
#include "Game.h"
#include"miniGame.h"
using namespace std::this_thread;

using namespace sf;
using namespace std;

int main() {



    //a partir d'ici, ca va dans game.play les petits boutchous
    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;
    chrono::duration<double> elapsedTime;

    // variable de game.h si je me trompe pas gang gang
    RenderWindow window(VideoMode(1489, 823), "La valley des poissons");
    window.setFramerateLimit(60);
    Terain terain;
    PC player("willy");
    ShopKeeper pierre("pierre");
    MiniGame miniGame;
    Game game;
    startTime = chrono::steady_clock::now(); // Start the timer

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {

            //  game.showMenu(event, window); CA MARCHE MAIS PAS BONNE IMAGE
            window.clear();

            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::KeyPressed) {
                player.limit();//a changer de place
                {
                    switch (event.key.code)
                    {
                    case Keyboard::Escape:
                        /*game.window().close();*/
                        break;
                    case Keyboard::Up:
                        player.moveUp();
                        break;
                    case Keyboard::Down:
                        player.moveDown();
                        break;
                    case Keyboard::Left:
                        player.moveLeft();
                        break;
                    case Keyboard::Right:
                        player.moveRight();
                        break;
                    case Keyboard::P:
                        player.animation();
                        break;
                    case Keyboard::Space:
                        player.space();
                        miniGame.play(player.getLvl(), player.getPositionX(), player.getPositionY(), window, terain, player, pierre);
                        //code pour attraper le poisson
                        //code pour que l'encule arrete de pecher
                        break;

                    }
                }
            }
        }

            window.clear();

            window.draw(terain.ShowTerain());
            window.draw(pierre.ShowCharacter());
            window.draw(player.ShowCharacter());

            window.display();

            endTime = chrono::steady_clock::now(); // Stop the timer
            elapsedTime = endTime - startTime;
            cout << "Elapsed time: " << elapsedTime.count() << " seconds" << endl;

        }

        return 0;
    }
