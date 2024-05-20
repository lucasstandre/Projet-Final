#include "commonFish.h"

using namespace std;

void CommonFish::initialise()
{

	//poisson 1
	_commonFish[0].setFishTexture("C.GhostFish.png");
	_commonFish[0].setName("A Ghost Fish, almost scary!");

	//poisson 2
	_commonFish[1].setFishTexture("C.Herring.png");
	_commonFish[1].setName("A Herring, yourah!");

	//poisson 3
	_commonFish[2].setFishTexture("C.Lionfish.png");
	_commonFish[2].setName("Lion Fish, roarrr!");

	//poisson 4
	_commonFish[3].setFishTexture("C.Pufferfish.png");
	_commonFish[3].setName("A Puffer fish, ochinchin no daisuki!");

	//poisson 5
	_commonFish[4].setFishTexture("C.Salmon.png");
	_commonFish[4].setName("A Salmon.. boring..");

	//poisson 6
	_commonFish[5].setFishTexture("C.Sunfish.png");
	_commonFish[5].setName("A Sunfish, holy cannoli!");

	//poisson 7
	_commonFish[6].setFishTexture("C.Walleye.png");
	_commonFish[6].setName("A Walleye, cool!");

	for (int i = 0; i < 7; i++) {
		_commonFish[i].setExpReceived(1);
		_commonFish[i].setGoldValue(25);
		_name.setFont(_textFont);

	}
}

Fish& CommonFish::returnFish(int fishValue)
{
	return _commonFish[fishValue];
}

