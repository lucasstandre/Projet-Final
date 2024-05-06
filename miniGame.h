#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include "SFML/Graphics.hpp"

class MiniGame {
private:
	int playerLevel = 1, //lvl du personnage
		playerBar = 96 + (8 * playerLevel), // permet de changer la barre du joueur en fonction de son niveau
		randomFirstFishPos = rand() % 568, //premiere position en y du poisson
		waitedTime = 0, //notre compteur de boucles
		waitTime = rand() % 40 + 5, //une fois sur la fishpos, nombre de boucle a faire avant de rebouger
		fishPos = rand() % 568, //definit aléatoirement une pos en y pour le fish a aller
		fishSpeed = rand() % 4 + 1; //vitesse aléatoire auquel le poisson bouge

	bool keyPressed = false, //permet de savoir si on a appuyé sur spacebar dans le minigame
		lostMiniGame = false,
		winMiniGame = false;

	sf::RectangleShape _barreMiniGame;
	sf::RectangleShape _greenBar;
	sf::RectangleShape _fish;
	sf::RectangleShape _scoreBar;
	sf::RectangleShape _completedScoreBar;

public:

	void initatialiseShapes();
	void setPosition();
	void play();

	~MiniGame();

};