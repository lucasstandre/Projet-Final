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
#include "Fish.h"
#include "commonFish.h"
#include "rareFish.h"
#include "eliteFish.h"
using namespace std::this_thread;

using namespace sf;
using namespace std;

int main() {



    //a partir d'ici, ca va dans game.play les petits boutchous
    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;
    chrono::duration<double> elapsedTime;

    // variable de game.h si je me trompe pas gang gang
    bool isMiniGameIsActive = false;
    bool canPlay = false;
    bool spacePressed = false;
    RenderWindow window(VideoMode(1489, 823), "La valley des poissons");
    window.setFramerateLimit(60);
    Terain terain;
    PC player("willy");
    ShopKeeper pierre("pierre");
    MiniGame miniGame;
    Game game;
    Fish earnedFish;
    CommonFish allCommonFish; //a enlever
    RareFish allRareFish;
    EliteFish allEliteFish;
    int fishValue; //important!! noue permet de savoir quelle poisson on veut exactement
    int lootDrop;
    int compteurBoucle = 0;
    startTime = chrono::steady_clock::now(); // Start the timer

    allCommonFish.initialise();
    allRareFish.initialise();
    allEliteFish.initialise();

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
                        spacePressed = true;
                        player.space();

                        //code pour que l'encule se batard de willy arrete de pecher
                        break;

                    }
                }
            }
        }
        if(spacePressed)
        canPlay = miniGame.waitingTime();


        if (canPlay == true) {   //si on a le temps on ajouter un "!" comme dans le vrai jeu       

            isMiniGameIsActive = miniGame.play(player.getLvl(), player.getPositionX(), player.getPositionY(), window, terain, player, pierre);

            if (isMiniGameIsActive == true) {

                spacePressed = false; //remet a defaut

                lootDrop = miniGame.loot(1000);

                if (lootDrop >= 900) { // si on loot elite

                    lootDrop = miniGame.loot(1);

                    earnedFish = allEliteFish.returnFish(lootDrop);

                    earnedFish.setFishTexture(allCommonFish.returnFish(lootDrop).getFishTexture());
                }
                else if (lootDrop >= 800) { // si on loot rare

                    lootDrop = miniGame.loot(4);

                    earnedFish = allRareFish.returnFish(lootDrop);

                    earnedFish.setFishTexture(allCommonFish.returnFish(lootDrop).getFishTexture());

                }
                else if (lootDrop <= 500) { // si on loot common

                    lootDrop = miniGame.loot(7);

                    earnedFish = allCommonFish.returnFish(lootDrop);

                    earnedFish.setFishTexture(allCommonFish.returnFish(lootDrop).getFishTexture());

                }
            }
        }
            window.clear();

            window.draw(terain.ShowTerain());
            window.draw(pierre.ShowCharacter());
            window.draw(player.ShowCharacter());

            if (isMiniGameIsActive != false) {

                        compteurBoucle++;

                window.draw(earnedFish.displayWindow());
                   window.draw(earnedFish.displayFish());
                window.draw(earnedFish.displayTextFish());

                if(compteurBoucle == 15)
                isMiniGameIsActive = false;  // Reset the mini-game status

                canPlay = false;
                compteurBoucle = 0;
            }
            window.display();

            endTime = chrono::steady_clock::now(); // Stop the timer
            elapsedTime = endTime - startTime;
            cout << "Elapsed time: " << elapsedTime.count() << " seconds" << endl;

        }

        return 0;
    }
