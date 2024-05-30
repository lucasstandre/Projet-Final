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
	_eliteFish[0].setExpReceived(0.50);
	_eliteFish[0].setGoldValue(200);

	//poisson 2
	_eliteFish[1].setFishTexture("E.Ms._Angler.png");
	_eliteFish[1].setName("Ms Angler.. hmmm big lips... big... lips...");
	_eliteFish[1].setExpReceived(0.50);
	_eliteFish[1].setGoldValue(200);

	_name.setFont(_textFont);	
}

Fish& EliteFish::returnFish(int fishValue)
{
	return _eliteFish[fishValue];
}
