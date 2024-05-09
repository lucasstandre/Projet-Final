#include "miniGame.h"

using namespace std;
using namespace sf;

void MiniGame::initatialiseShapes()
{
	_barreMiniGame.setSize(sf::Vector2f(40, 568));
	_greenBar.setSize(sf::Vector2f(40, playerBar));
	_fish.setSize(sf::Vector2f(10, 10));
	_scoreBar.setSize(sf::Vector2f(20, 568));
	_completedScoreBar.setSize(sf::Vector2f(20, 568 / 2));
}

void MiniGame::setPosition()
{
	_greenBar.setFillColor(sf::Color(100, 250, 50)); //couleur vert
	_greenBar.setPosition(sf::Vector2f(0, 568 / 2));

	_scoreBar.setPosition(sf::Vector2f(60, 0));

	_fish.setFillColor(sf::Color(100, 100, 100));
	_fish.setPosition(sf::Vector2f(15, rand() % 568));// chiffre a changer

	_completedScoreBar.setFillColor(sf::Color(100, 250, 50)); //couleur vert
	_completedScoreBar.setPosition(sf::Vector2f(60, 568 / 2));

}

void MiniGame::play()
{
	RenderWindow window(VideoMode(1489, 823), "La valley des poissons"); // a enlever

	window.setFramerateLimit(60); // a enlever

	while (window.isOpen()) {
		Event event;

		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {

				window.close();

			}
			else if (event.type == Event::KeyPressed) {

				switch (event.key.code)
				{
				case Keyboard::Escape:

					window.close();

					break;

				case Keyboard::Space:

					if (_greenBar.getPosition().y > 0)
					{

						_greenBar.move(0, -10);

						keyPressed = true; // cette ligne empeche que la barre aille par en bas lorsque le joueur appuie sur spacebar

					}

				}
			}
		}

		if (!keyPressed && _greenBar.getPosition().y + playerBar + 1 < 568) //fait en sorte de descendre la greenbar par defaut
			_greenBar.move(0, 3);



		if (fishPos == _fish.getPosition().y) { // regenere une nouvelle pos

			waitedTime++;

			if (waitedTime == waitTime) { //cette ligne permet au fish de rester en place un nombre aléatoire de tours

				fishPos = rand() % 568;

				fishSpeed = rand() % 4 + 1;

				waitTime = rand() % 40 + 5;

				waitedTime = 0;

			}
		}
		else if (_fish.getPosition().y < fishPos) {

			_fish.move(0, fishSpeed);

			if (_fish.getPosition().y > fishPos)

				fishPos = _fish.getPosition().y; // si le fish depasse le fishpos, cette ligne permet de s'assurer que fishpos va etre egal au pos du fish

		}
		else if (_fish.getPosition().y > fishPos) {

			_fish.move(0, -fishSpeed);

			if (_fish.getPosition().y < fishPos)

				fishPos = _fish.getPosition().y; // si le fish depasse le fishpos, cette ligne permet de s'assurer que fishpos va etre egal au pos du fish

		}
		if (_fish.getPosition().y < _greenBar.getPosition().y + playerBar && _fish.getPosition().y > _greenBar.getPosition().y) { //fait monter la barre verte jpense

			_completedScoreBar.setSize(sf::Vector2f(20, _completedScoreBar.getSize().y + 1));

			_completedScoreBar.move(0, -1);

		}
		else {
			if (_completedScoreBar.getSize().y != 0) {

				_completedScoreBar.setSize(sf::Vector2f(20, _completedScoreBar.getSize().y - 1)); //fait descendre la barre verte jpense

				_completedScoreBar.move(0, 1);
			}

		}

		window.clear();

		window.draw(_barreMiniGame);

		window.draw(_greenBar);

		window.draw(_fish);

		window.draw(_scoreBar);

		window.draw(_completedScoreBar);

		window.display();

		keyPressed = false;
	}

	system("pause");
}

MiniGame::~MiniGame()
{
	playerLevel = 0; //lvl du personnage
	playerBar = 0; // permet de changer la barre du joueur en fonction de son niveau
	randomFirstFishPos = 0; //premiere position en y du poisson
	waitedTime = 0; //notre compteur de boucles
	waitTime = 0; //une fois sur la fishpos, nombre de boucle a faire avant de rebouger
	fishPos = 0; //definit aléatoirement une pos en y pour le fish a aller
	fishSpeed = 0; //vitesse aléatoire auquel le poisson bouge

	bool keyPressed = false, //permet de savoir si on a appuyé sur spacebar dans le minigame
		lostMiniGame = false,
		winMiniGame = false;
}

