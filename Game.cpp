#include "Game.h"



using namespace sf;
using namespace std;


Game::Game()
{
    bool _isMiniGameWon = false;
    bool _canPlay = false;
    bool _spacePressed = false;
   _terrain;
   _player;
   _pierre;
   _miniGame;
   _earnedFish;
   _allCommonFish;
   _allRareFish;
   _allEliteFish;
   _fishValue = 0;
   _lootDrop= 0;
   _compteurBoucle = 0;
   _window;
   _backgroundMusic;
}

Game::~Game() {

    bool _isMiniGameWon = false;
    bool _canPlay = false;
    bool _spacePressed = false;
    _fishValue = 0;
    _lootDrop = 0;
    _compteurBoucle = 0;

}
void Game::initializeAllFish()
{
    _allCommonFish.initialise();
    _allRareFish.initialise();
    _allEliteFish.initialise();
}

void Game::initializeBgMusic()
{
    _backgroundMusic.openFromFile("OST1.ogg");
    _backgroundMusic.setLoop(true); // This will make the music loop
    _backgroundMusic.play();

}

void Game::initializeWindow()
{
    VideoMode mode(1489, 823);
    _window.create(mode, "La valley des poissons");
    _window.setFramerateLimit(60);
}

void Game::initializeExclamationPoint()
{
    _exclamationPointTexture.loadFromFile("!_brun.png");

    if (!_exclamationPointTexture.loadFromFile("!_brun.png"))
        cout << "point exclamation non chargé..";

    _exclamationPoint.setTexture(&_exclamationPointTexture);
    _exclamationPoint.setSize(sf::Vector2f(712, 712));

    _bufferExclamationPoint.loadFromFile("miniGame.ogg");

    if (!_bufferExclamationPoint.loadFromFile("miniGame.ogg"))
        cout << "point exclamation non chargé..";

    _soundExclamationPoint.setBuffer(_bufferExclamationPoint);
}

void Game::initializeLoseScreen()
{
    _loseScreenTexture.loadFromFile("LOST.JPG");

    if (!_loseScreenTexture.loadFromFile("LOST.JPG"))
     cout << "erreur de texture dans le losing screen..";

    _loseScreen.setSize(sf::Vector2f(459, 277));
    _loseScreen.setTexture(&_loseScreenTexture);
    _loseScreen.setPosition(sf::Vector2f(500, 250));

    _bufferLost.loadFromFile("LOST.ogg");

    if (!_bufferLost.loadFromFile("LOST.ogg"))
        cout << "LOST non chargé..";

    _soundLost.setBuffer(_bufferLost);

}

void Game::setText(int willy, int pos, string nameWilly)
{
    string text = nameWilly+" has " + to_string(willy) + "g";
    _name.setString(text);
    _name.setPosition(sf::Vector2f(600, pos));

    _textFont.loadFromFile("Stardew_Valley.ttf");

    if (!_textFont.loadFromFile("Stardew_Valley.ttf"))
    {
        cout << "erreur de police!";
    }
    _name.setFillColor(sf::Color(165, 42, 42));


    _name.setFont(_textFont);
    _name.setCharacterSize(40);
}


void Game::save(string characterSaveFile, int moneyPC)
{
    fstream monFlux;
    monFlux.open(characterSaveFile+"Save.txt");

    if (!monFlux.is_open())
    {
        exit(1);
    }

    monFlux << moneyPC;
    monFlux.close();

}

void Game::initializeAll()
{
    initializeAllFish();
    initializeBgMusic();
    initializeWindow();
    initializeExclamationPoint();
    initializeLoseScreen();
}



void Game::start() {
    initializeAll();
    startMenu();
}

void Game::startMenu()
{

    fstream saveFile;
    RectangleShape menu(Vector2f(1489, 823));
    Texture texturemenu;
    texturemenu.loadFromFile("Menu1.jpg");
    menu.setTexture(&texturemenu);

    _window.clear();
    _window.draw(menu);
    _window.display();

    int moneyWilly=0;
    int moneyPrettyWilly=0;
    int moneyEmoWilly=0;

    PC Willy("willy");
    PC prettyWilly("prettywilly");
    PC emoWilly("emowilly");

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
    while (_window.isOpen())
    {
        while (_window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                _window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case Keyboard::Num1:
                    texturemenu.loadFromFile("Willychoicemenu.jpg");
                    menu.setTexture(&texturemenu);
                    _window.clear();
                    _window.draw(menu);
                    _window.display();

                    while (true)
                    {
                        if (_window.pollEvent(event))
                        {
                            if (event.type == sf::Event::Closed)
                            {
                                _window.close();
                                return;
                            }
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                            {
                                startMenu();
                            }

                            if (event.type == sf::Event::KeyPressed)
                            {
                                switch (event.key.code)
                                {
                                case Keyboard::Num1:
                                    texturemenu.loadFromFile("Willymenu.jpg");
                                    menu.setTexture(&texturemenu);
                                    _window.clear();
                                    _window.draw(menu);
                                    _window.display();

                                    while (true)
                                    {
                                        if (_window.pollEvent(event))
                                        {
                                            if (event.type == sf::Event::Closed)
                                            {
                                                _window.close();
                                                return;
                                            }
                                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                                            {
                                                startMenu();

                                            }

                                            if (event.type == sf::Event::KeyPressed)
                                            {
                                                switch (event.key.code)
                                                {
                                                case Keyboard::Num1:
                                                    _player.setMoney(moneyWilly);
                                                    _nameSave = "Willy";
                                                    Play();
                                                    break;
                                                case Keyboard::Num2:
                                                    moneyWilly = 0; // reset Willy's money
                                                    Willy.setMoney(0); // reset Willy's money
                                                    _nameSave = "Willy";
                                                    Play();
                                                    break;
                                                case Keyboard::Escape:
                                                    texturemenu.loadFromFile("Menu1.jpg");
                                                    menu.setTexture(&texturemenu);
                                                    _window.clear();
                                                    _window.draw(menu);
                                                    _window.display();
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
                                    _window.clear();
                                    _window.draw(menu);
                                    _window.display();

                                    while (true)
                                    {
                                        if (_window.pollEvent(event))
                                        {
                                            if (event.type == sf::Event::Closed)
                                            {
                                                _window.close();
                                                return;
                                            }
                                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                                            {
                                                startMenu();
                                            }

                                            if (event.type == sf::Event::KeyPressed)
                                            {
                                                switch (event.key.code)
                                                {
                                                case Keyboard::Num1:
                                                    _player.setCharacter("prettywilly");
                                                    _player.setMoney(moneyPrettyWilly);
                                                    _nameSave = "PrettyWilly";
                                                    Play();
                                                    break;
                                                case Keyboard::Num2:
                                                    moneyPrettyWilly = 0; // reset Pretty Willy's money
                                                    prettyWilly.setMoney(0); // reset Pretty Willy's money
                                                    _player.setCharacter("prettywilly");
                                                    _nameSave = "PrettyWilly";
                                                    Play();
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
                                    _window.clear();
                                    _window.draw(menu);
                                    _window.display();

                                    while (true)
                                    {
                                        if (_window.pollEvent(event))
                                        {
                                            if (event.type == sf::Event::Closed)
                                            {
                                                _window.close();
                                                return;
                                            }
                                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                                            {
                                                startMenu();
                                            }

                                            if (event.type == sf::Event::KeyPressed)
                                            {
                                                switch (event.key.code)
                                                {
                                                case Keyboard::Num1:
                                                    _player.setCharacter("emowilly");
                                                    _player.setMoney(moneyEmoWilly);
                                                    _nameSave = "EmoWilly";
                                                    Play();
                                                    
                                                    break;
                                                case Keyboard::Num2:
                                                    moneyEmoWilly = 0; // reset Emo Willy's money
                                                    emoWilly.setMoney(0); // reset Emo Willy's money
                                                    _player.setCharacter("emowilly");
                                                    _nameSave = "EmoWilly";
                                                    Play();
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
                    texturemenu.loadFromFile("controlsFinal.jpg");
                    menu.setTexture(&texturemenu);
                    menu.setScale(4.45, 4.45);
                    _window.clear();
                    _window.draw(menu);
                    _window.display();

                    while (true)
                    {
                        if (_window.pollEvent(event))
                        {
                            if (event.type == sf::Event::Closed)
                            {
                                _window.close();
                                return;
                            }
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                            {
                                startMenu();
                            }
                        }
                    }
                    break;

                case Keyboard::Num3:

                    texturemenu.loadFromFile("menuBG.jpg");
                    menu.setTexture(&texturemenu);
                    menu.setScale(4.45, 4.45);
                    
                    _window.clear();
                    _window.draw(menu);


                    setText(moneyWilly,300, "Willy");
                    _window.draw(_name);
                    setText(moneyPrettyWilly,400, "Pretty Willy");
                    _window.draw(_name);
                    setText(moneyEmoWilly,500, "Emo Willy");
                    _window.draw(_name);
                    _window.display();
                    

                    while (true)
                    {
                        if (_window.pollEvent(event))
                        {
                            if (event.type == sf::Event::Closed)
                            {
                                _window.close();
                                return;
                            }
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                            {
                                startMenu();
                            }
                        }
                    }
                    break;



                case Keyboard::Num4:
                    texturemenu.loadFromFile("fishGuide.jpg");
                    menu.setTexture(&texturemenu);
                    _window.clear();
                    _window.draw(menu);
                    _window.display();

                    while (true)
                    {
                        if (_window.pollEvent(event))
                        {
                            if (event.type == sf::Event::Closed)
                            {
                                _window.close();
                                return;
                            }
                            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                            {                          
                                startMenu();
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

void Game::Play()
{

    while (_window.isOpen()) {
        Event event;


        while (_window.pollEvent(event)) {


            _window.clear();

            if (event.type == Event::Closed) {
                _window.close();
            }
            else if (event.type == Event::KeyPressed) {
                switch (event.key.code) {
                case Keyboard::Escape:
                    _window.close();
                    break;
                case Keyboard::Up:
                    _player.moveUp();
                    _spacePressed = false;
                    break;
                case Keyboard::Down:
                    _player.moveDown();
                    _spacePressed = false;
                    break;
                case Keyboard::Left:
                    _player.moveLeft();
                    _spacePressed = false;
                    break;
                case Keyboard::Right:
                    _player.moveRight();
                    _spacePressed = false;
                    break;
                case Keyboard::P:
                    _player.animation();
                    _spacePressed = false;
                    break;
                case Keyboard::S:
                    save(_nameSave, _player.getMoney());

                    break;
                case Keyboard::Space:
                    if (_player.getPositionY() >= 465) {
                        _spacePressed = true;
                        _player.space();
                    }
                    break;
                case Keyboard::C:
                    if (_player.getPositionX() < 985 && _player.getPositionX() > 885) {
                        handleShopInteraction();
                    }
                    break;
                default:
                    break;
                }
            }
        }

        // Update and render game state
        if (_spacePressed) {
            if (_spacePressed == true)
                _canPlay = _miniGame.waitingTime();
        }

        if (_playable == true) {

            _isMiniGameWon = _miniGame.play(_player.getLvl(), _player.getPositionX(), _player.getPositionY(), _window, _terrain, _player, _pierre);

            if (_isMiniGameWon == true) {

                _spacePressed = false; //remet a defaut

                _playable = false;

                _lootDrop = _miniGame.loot(1000);

                if (_lootDrop >= 900) { // si on loot elite

                    _lootDrop = _miniGame.loot(2);

                    _earnedFish = _allEliteFish.returnFish(_lootDrop);

                    _earnedFish.setFishTexture(_allEliteFish.returnFish(_lootDrop).getFishTexture());
                }
                else if (_lootDrop >= 501) { // si on loot rare

                    _lootDrop = _miniGame.loot(4);

                    _earnedFish = _allRareFish.returnFish(_lootDrop);

                    _earnedFish.setFishTexture(_allRareFish.returnFish(_lootDrop).getFishTexture());

                }
                else if (_lootDrop <= 500) { // si on loot common

                    _lootDrop = _miniGame.loot(7);

                    _earnedFish = _allCommonFish.returnFish(_lootDrop);

                    _earnedFish.setFishTexture(_allCommonFish.returnFish(_lootDrop).getFishTexture());

                }
            }
            else {
                _ifLost = true;
            }
        }
        _window.clear();

        _window.draw(_terrain.ShowTerrain());
        _window.draw(_pierre.ShowCharacter());
        _window.draw(_player.ShowCharacter());
        _window.draw(_terrain.ShowG());
        _window.draw(_player.showMoney());

        if (_canPlay != false) {

            _spacePressed = false;
            _compteurBoucle++;

            if (_compteurBoucle == 1)
                _soundExclamationPoint.play();


            if (_compteurBoucle > 10) {
                _exclamationPoint.setPosition(_player.getPositionX() - 275, _player.getPositionY() - 250);
                _window.draw(_exclamationPoint);
            }


            if (_compteurBoucle == 50) {
                _compteurBoucle = 0;
                _playable = true;
                _canPlay = false;
                _spacePressed = true;
            }
        }
        if (_ifLost == true) {

            _compteurBoucle++;
            _playable = false;
            _spacePressed = false;


            if (_compteurBoucle == 1) {
                _soundLost.play();
            }

            _window.draw(_loseScreen);

            if (_compteurBoucle == 130) {

                _ifLost = false;
                _compteurBoucle = 0;
                _spacePressed = true;



            }
        }
        if (_isMiniGameWon == true) {

            _compteurBoucle++;
            _spacePressed = false;
            


            _window.draw(_earnedFish.displayWindow());
            _window.draw(_earnedFish.displayFish());
            _window.draw(_earnedFish.displayTextFish());


            if (_compteurBoucle == 130) {

                _isMiniGameWon = false;
                _spacePressed = true;
                _compteurBoucle = 0;

                _player.setMoney(_player.getMoney() + _earnedFish.getGoldValue());
                _player.setLvl(_earnedFish.getExpReceived());
            }
        }
        _window.display();

    }
}
void Game::handleShopInteraction() {
    bool interacting = true;
    //_pierre.setShop();
    _pierre.setText("Tu as " + std::to_string(_player.getPS5()) + " PS5\nAppuyer sur 1 pour acheter une ps5 a 500g \nAppuyer sur 2 pour quitter");

    while (interacting) {
        _window.clear();
        _window.draw(_terrain.ShowTerrain());
        _window.draw(_pierre.ShowCharacter());
        _window.draw(_player.ShowCharacter());
        _window.draw(_terrain.ShowG());
        _window.draw(_player.showMoney());
        _pierre.drawShop(_window);
        _window.display();

        Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Num1:
                    if (_player.getMoney() >= 500) {
                        _player.buyPS5();
                        _pierre.setText("Tu a acheter une PS5 !!!!");
                    }
                    else {
                        _pierre.setText("Tu na pas asser dargent pour une ps5");
                    }
                    break;
                case sf::Keyboard::Num2:
                    _pierre.setText("A plus!");
                    interacting = false;
                    break;
                default:
                    break;
                }

                // Redraw the shop interaction with updated text
                _window.clear();
                _window.draw(_terrain.ShowTerrain());
                _window.draw(_pierre.ShowCharacter());
                _window.draw(_player.ShowCharacter());
                _window.draw(_terrain.ShowG());
                _window.draw(_player.showMoney());
                _pierre.drawShop(_window);
                _window.display();
            }
        }
    }   
    sf::Clock clock;
while (clock.getElapsedTime().asSeconds() < 2) {
}
}
