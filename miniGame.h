#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include"Terain.h"
#include"PC.h"
#include"ShopKeeper.h"
#include "SFML/Graphics.hpp"

class MiniGame {
private:
	int _playerLevel = 1, //lvl du personnage
		_waitedTime = 0, //notre compteur de boucle
		_waitTime = rand() % 40 + 5, //une fois sur la fishpos, nombre de boucle a faire avant de rebouger
		_fishPos, //definit aléatoirement une pos en y pour le fish a aller
		_fishSpeed = rand() % 4 + 1, //vitesse aléatoire auquel le poisson bouge
		_compteurBoucle = 0;

	bool keyPressed = false, //permet de savoir si on a appuyé sur spacebar dans le minigame
		lostMiniGame = false,
		winMiniGame = false;

	double _playerBar = 96 + (8 * _playerLevel); // permet de changer la barre du joueur en fonction de son niveau

	sf::RectangleShape _barreMiniGame;
	sf::RectangleShape _allMiniGame;
	sf::RectangleShape _greenBar;
	sf::RectangleShape _fish;
	sf::RectangleShape _scoreBar;
	sf::RectangleShape _completedScoreBar;
	sf::Texture _miniGameTexture;
	sf::Texture _fishTexture;

public:
	MiniGame();
	void setPlayerBar(double playerLevel); //set la barre du joueur en fonction de son lvl
	void initatialiseShapes(); //setsize et settexture de tout les rectangle
	void initialisePosition(int playerPosX, int playerposY); //set la position en fonction du joueur
	void initialiseColor(); //set la color
	bool waitingTime();
	bool play(int playerLevel, int playerPosX, int playerPosY, sf::RenderWindow &window, Terain &terrain, PC player, ShopKeeper shopKeeper); //bool qui return true si on gagne le mini game et false si on perd
	int loot(int odds);

	~MiniGame();

};