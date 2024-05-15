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
         Game game;
        game.showMenu();
        //chrono::steady_clock::time_point startTime;
        //chrono::steady_clock::time_point endTime;
        //chrono::duration<double> elapsedTime;

        //// Création de la fenêtre
        //RenderWindow window(VideoMode(1489, 823), "La valley des poison");
        //window.setFramerateLimit(60);
        //Terain terain;
        //PC willy("willy");
        //ShopKeeper pierre("pierre");
        //MiniGame miniGame;

        //startTime = chrono::steady_clock::now(); // Start the timer

        //while (window.isOpen()) {
        //    Event event;
        //    while (window.pollEvent(event)) {
        //        if (event.type == Event::Closed) {
        //            window.close();
        //        }
        //        else if (event.type == Event::KeyPressed) {
        //            willy.move(event);
        //            cout << "Willy position: " << willy.getPositionX() << ", " << willy.getPositionY() << endl;
        //            willy.limit();
        //        }
        //    }

        //    window.clear();

        //    window.draw(terain.ShowTerain());
        //    window.draw(pierre.ShowCharacter());
        //    window.draw(willy.ShowCharacter());

        //    window.display();

        //    endTime = chrono::steady_clock::now(); // Stop the timer
        //    elapsedTime = endTime - startTime;
        //    cout << "Elapsed time: " << elapsedTime.count() << " seconds" << endl;

        //}

        return 0;
    }