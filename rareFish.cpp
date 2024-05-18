#include "rareFish.h"

using namespace std;

void RareFish::initialise()
{
	_textFont.loadFromFile("Stardew_Valley.ttf");

	if (!_textFont.loadFromFile("Stardew_Valley.ttf"))
	{
		cout << "erreur de police!";
	}

	//poisson 1
	_rareFish[0].setFishTexture("R.Angler.png");
	_rareFish[0].setName("a Angler, it's rare!");

	//poisson 2
	_rareFish[1].setFishTexture("R.Blobfish.png");
	_rareFish[1].setName("a Blobfish, looks a lot like LUCAS ST-ANDRE..");

	//poisson 3
	_rareFish[2].setFishTexture("R.Blue_Discus.png");
	_rareFish[2].setName("Jeez Louise, a Blue Discus!");

	//poisson 4
	_rareFish[3].setFishTexture("R.Midnight_squid.png");
	_rareFish[3].setName("a Midnight Squid, uwu");

	for (int i = 0; i < 4; i++) {
		_rareFish[i].setExpReceived(5);
		_rareFish[i].setGoldValue(50);
		_name.setFont(_textFont);
	}
}

Fish& RareFish::returnFish(int fishValue)
{
	return _rareFish[fishValue];
}
