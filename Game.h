#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <fstream>
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

class Game
{
private:
    bool _isMiniGameWon = false;
    bool _canPlay = false;
    bool _spacePressed = false;
    Terain _terrain;
    PC _player;
    ShopKeeper _pierre;
    MiniGame _miniGame;
    Fish _earnedFish;
    CommonFish _allCommonFish;
    RareFish _allRareFish;
    EliteFish _allEliteFish;
    int _fishValue;
    int _lootDrop;
    int _compteurBoucle = 0;
    sf::RenderWindow _window;
    sf::Music _backgroundMusic;

public:

    Game();
   
    void initializeAllFish();
    void initializeBgMusic();
    void initializeWindow();
    void initializeAll();

    void Play();
    void start();
    void save(std::string characterSaveFile, int moneyPC);
    void startMenu();


    ~Game();
};
