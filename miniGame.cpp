#include "miniGame.h"

using namespace std;
using namespace sf;

void MiniGame::setPlayerBar(double playerLevel)
{
	assert(playerLevel >= 0);
	_playerLevel = playerLevel;
	_playerBar = 96 + (8 * _playerLevel); // permet de changer la barre du joueur en fonction de son niveau

}

void MiniGame::initatialiseShapes()
{
	_barreMiniGame.setSize(sf::Vector2f(25, 370));

	_allMiniGame.setSize(sf::Vector2f(111, 425));

	_greenBar.setSize(sf::Vector2f(24, _playerBar));

	_fish.setSize(sf::Vector2f(15, 15));

	_scoreBar.setSize(sf::Vector2f(10, 400));

	_completedScoreBar.setSize(sf::Vector2f(10, 400 / 2));

	_miniGameTexture.loadFromFile("fishingBarSprite.png");

	if (!_miniGameTexture.loadFromFile("fishingBarSprite.png"))
	{
		cout << "erreur dans la texture";
	}
	_allMiniGame.setTexture(&_miniGameTexture);

	_fishTexture.loadFromFile("C.Salmon.png");

	if (!_fishTexture.loadFromFile("C.Salmon.png"))
	{
		cout << "erreur dans la texture";
	}
	_fish.setTexture(&_fishTexture);

}

void MiniGame::initialisePosition(int playerPosX, int playerPosY)//multiplie la pos x par la pos du joueur pour le faire apparaitre la ou on veut

{
	_allMiniGame.setPosition(sf::Vector2f(playerPosX + 20, playerPosY-75));

	_greenBar.setPosition(sf::Vector2f(73 + (playerPosX + 20), (370 / 2) + 20 + (playerPosY-75)));

	_barreMiniGame.setPosition(sf::Vector2f(73 + (playerPosX + 20), 20 + (playerPosY-75)));

	_scoreBar.setPosition(sf::Vector2f(112 + (playerPosX + 20), 10 + (playerPosY-75)));

	_fish.setPosition(sf::Vector2f(78 + (playerPosX + 20), (rand() % 370 + 20) + (playerPosY -75)));// chiffre a changer

	_completedScoreBar.setPosition(sf::Vector2f(112 + (playerPosX + 20), 400 / 2 + 10 + (playerPosY-75)));
}

void MiniGame::initialiseColor()
{
	_greenBar.setFillColor(sf::Color(100, 250, 50)); //couleur vert

	_completedScoreBar.setFillColor(sf::Color(100, 250, 50)); //couleur vert

	_scoreBar.setFillColor(sf::Color(139, 69, 19)); //couleur vert

	_barreMiniGame.setFillColor(sf::Color::Transparent);

	_fish.setFillColor(sf::Color(100, 100, 100));
}

bool MiniGame::waitingTime()
{
	srand(time(0));

	int loopToDo = rand() % 500 + 50;

	if (_compteurBoucle == loopToDo) {
		_compteurBoucle = 0;
		return true;
	}
	else {
		_compteurBoucle++;
		return false;
	}
}

bool MiniGame::play(int playerLevel, int playerPosX, int playerPosY, RenderWindow& window, Terain& terrain, PC player, ShopKeeper shopKeeper)
{

	setPlayerBar(playerLevel);

	initatialiseShapes();

	initialisePosition(playerPosX, playerPosY);

	initialiseColor();

	_fishPos = rand() % 370 + 20 + (playerPosY-75);

	while (true) {
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
					keyPressed = true; // cette ligne empeche que la barre aille par en bas lorsque le joueur appuie sur spacebar

					if (_greenBar.getPosition().y > 25 + (playerPosY-75))
					{
						_greenBar.move(0, -10);
					}


				}
			}
		}

		if (!keyPressed && _greenBar.getPosition().y + _playerBar + 1 <= 395 + (playerPosY)-75) //fait en sorte de descendre la greenbar par defaut
			_greenBar.move(0, 3);



		if (_fishPos == _fish.getPosition().y) { // regenere une nouvelle pos

			_waitedTime++;

			if (_waitedTime == _waitTime) { //cette ligne permet au fish de rester en place un nombre aléatoire de tours

				_fishPos = (rand() % 370 + 20 + (playerPosY-75));

				_fishSpeed = rand() % 4 + 1;

				_waitTime = rand() % 40 + 5;

				_waitedTime = 0;

			}
		}
		else if (_fish.getPosition().y < _fishPos) {

			_fish.move(0, _fishSpeed);

			if (_fish.getPosition().y > _fishPos)

				_fishPos = _fish.getPosition().y; // si le fish depasse le fishpos, cette ligne permet de s'assurer que fishpos va etre egal au pos du fish

		}
		else if (_fish.getPosition().y > _fishPos) {

			_fish.move(0, -_fishSpeed);

			if (_fish.getPosition().y < _fishPos)

				_fishPos = _fish.getPosition().y; // si le fish depasse le fishpos, cette ligne permet de s'assurer que fishpos va etre egal au pos du fish

		}
		if (_fish.getPosition().y < _greenBar.getPosition().y + _playerBar && _fish.getPosition().y > _greenBar.getPosition().y) { //fait monter la barre verte jpense

			_completedScoreBar.setSize(sf::Vector2f(10, _completedScoreBar.getSize().y + 1));

			_completedScoreBar.move(0, -1);

		}
		else {
			if (_completedScoreBar.getSize().y != 0) {

				_completedScoreBar.setSize(sf::Vector2f(10, _completedScoreBar.getSize().y - 1)); //fait descendre la barre verte jpense

				_completedScoreBar.move(0, 1);

			}

		}

		window.clear();

		window.draw(terrain.ShowTerain());

		window.draw(shopKeeper.ShowCharacter());

		window.draw(player.ShowCharacter());

		window.draw(_allMiniGame);

		window.draw(_barreMiniGame);

		window.draw(_greenBar);

		window.draw(_fish);

		window.draw(_scoreBar);

		window.draw(_completedScoreBar);

		window.display();




		keyPressed = false;

		if (_completedScoreBar.getSize().y == _scoreBar.getSize().y) { //return true si le mini game est gagné

			winMiniGame = true;

			window.clear();

			return true;

			
		}
		if (_completedScoreBar.getSize().y + 370 == _scoreBar.getSize().y) { //return false si le minigame est perdu

			lostMiniGame = true;

			window.clear();

			return false;

		}
	}
}

int MiniGame::loot(int odds)
{
	srand(time(0));
	int dropRate = rand() % odds;

	if (dropRate == odds)
		odds--;
	
	return dropRate;
}

MiniGame::~MiniGame()
{
	_playerLevel = 0; //lvl du personnage
	_playerBar = 0; // permet de changer la barre du joueur en fonction de son niveau
	_waitedTime = 0; //notre compteur de boucles
	_waitTime = 0; //une fois sur la fishpos, nombre de boucle a faire avant de rebouger
	_fishPos = 0; //definit aléatoirement une pos en y pour le fish a aller
	_fishSpeed = 0; //vitesse aléatoire auquel le poisson bouge

	bool keyPressed = false, //permet de savoir si on a appuyé sur spacebar dans le minigame
		lostMiniGame = false,
		winMiniGame = false;
}

