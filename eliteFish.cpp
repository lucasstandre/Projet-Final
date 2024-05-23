#include "eliteFish.h"

using namespace std;

void EliteFish::initialise()
{
	_textFont.loadFromFile("Stardew_Valley.ttf");

	if (!_textFont.loadFromFile("Stardew_Valley.ttf"))
	{
		cout << "erreur de police!";
	}

	//poisson 1
	_eliteFish[0].setFishTexture("E.Blue_chicken.png");
	_eliteFish[0].setName("a blue chicken, HUUUUH !?!");

	//poisson 2
	_eliteFish[1].setFishTexture("E.Ms._Angler.png");
	_eliteFish[1].setName("Ms Angler.. hmmm big lips...");


	for (int i = 0; i < 2; i++) {
		_eliteFish[i].setExpReceived(0.50);
		_eliteFish[i].setGoldValue(100);
		_name.setFont(_textFont);
	}
}

Fish& EliteFish::returnFish(int fishValue)
{
	return _eliteFish[fishValue];
}
