#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
    int fishValue; 
    int lootDrop;
    int compteurBoucle = 0;
    allCommonFish.initialise();
    allRareFish.initialise();
    allEliteFish.initialise();

    Music backgroundMusic;
    backgroundMusic.openFromFile("OST1.ogg");
    backgroundMusic.setLoop(true); // This will make the music loop
    backgroundMusic.play();

   // game.showMenu(window);

    while (window.isOpen()) {
        Event event;

   
        while (window.pollEvent(event)) {

            cout <<player.getPositionX() << " " << player.getPositionY() << endl;
            //  game.showMenu(event, window); CA MARCHE MAIS PAS BONNE IMAGE
            window.clear();

            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::KeyPressed) {
                {
                    switch (event.key.code)
                    {
                    case Keyboard::Escape:
                        window.close();
                        break;
                    case Keyboard::Up:
                        player.moveUp();
                        spacePressed = false; //test
                        break;
                    case Keyboard::Down:
                        player.moveDown();
                        spacePressed = false; //test
                        break;
                    case Keyboard::Left:
                        player.moveLeft();
                        spacePressed = false; //test
                        break;
                    case Keyboard::Right:
                        player.moveRight();
                        spacePressed = false; //test
                        break;
                    case Keyboard::P:
                        player.animation();
                        spacePressed = false; //test
                        break;
                    case Keyboard::S:
                        game.save("willySave.txt", player.getMoney());
                        break;
                    case Keyboard::Space:
                        if (player.getPositionY()>=465)
                        {
                            spacePressed = true;
                            player.space();
                        }
                        else if (player.getPositionY() >= 405 && player.getPositionX() < 985 && player.getPositionX() > 885)
                        {

                                window.draw(pierre.shop());
                                //pierre.interact(quit);
                            
						}
                        //code pour que l'encule se batard de willy arrete de pecher
                        break;
                    }
                }
            }
        }
        if(spacePressed==true)
        canPlay = miniGame.waitingTime();


        if (canPlay == true) {   //si on a le temps on ajouter un "!" comme dans le vrai jeu       

            isMiniGameIsActive = miniGame.play(player.getLvl(), player.getPositionX(), player.getPositionY(), window, terain, player, pierre);

             if (isMiniGameIsActive == true) {

                spacePressed = false; //remet a defaut

                canPlay = false;

                lootDrop = miniGame.loot(1000);

                if (lootDrop >= 900) { // si on loot elite

                    lootDrop = miniGame.loot(2);

                    earnedFish = allEliteFish.returnFish(lootDrop);

                    earnedFish.setFishTexture(allEliteFish.returnFish(lootDrop).getFishTexture());
                }
                else if (lootDrop >= 800) { // si on loot rare

                    lootDrop = miniGame.loot(4);

                    earnedFish = allRareFish.returnFish(lootDrop);

                    earnedFish.setFishTexture(allRareFish.returnFish(lootDrop).getFishTexture());

                }
                else if (lootDrop <= 500) { // si on loot common

                    lootDrop = miniGame.loot(7);

                    earnedFish = allCommonFish.returnFish(lootDrop);

                         earnedFish.setFishTexture(allCommonFish.returnFish(lootDrop).getFishTexture());

                }
            }
            else {
               
            }
        }
            window.clear();

            window.draw(terain.ShowTerain());
            window.draw(pierre.ShowCharacter());
            window.draw(player.ShowCharacter());
            //draw money!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //draw level!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

            if (isMiniGameIsActive != false) {

                        compteurBoucle++;

                window.draw(earnedFish.displayWindow());
                window.draw(earnedFish.displayFish());
                window.draw(earnedFish.displayTextFish());

                if (compteurBoucle == 75) {
                    isMiniGameIsActive = false;  // Reset the mini-game status
                    compteurBoucle = 0;
                    player.setMoney(earnedFish.getGoldValue());
                    player.setLvl(earnedFish.getExpReceived());
                }

            }
            window.display();
        }

        return 0;
    }
