#include "commonFish.h"

using namespace std;

void CommonFish::initialise()
{

	//poisson 1
	_commonFish[0].setFishTexture("C.GhostFish.png");
	_commonFish[0].setName("A Ghost Fish, almost scary!");
	_commonFish[0].setExpReceived(0.1);
	_commonFish[0].setGoldValue(25);

	//poisson 2
	_commonFish[1].setFishTexture("C.Herring.png");
	_commonFish[1].setName("A Herring, is it disabled ?");
	_commonFish[1].setExpReceived(0.1);
	_commonFish[1].setGoldValue(25);

	//poisson 3
	_commonFish[2].setFishTexture("C.Lionfish.png");
	_commonFish[2].setName("A Lion Fish, wow so alpha male! roarr!");
	_commonFish[2].setExpReceived(0.1);
	_commonFish[2].setGoldValue(25);

	//poisson 4
	_commonFish[3].setFishTexture("C.Pufferfish.png");
	_commonFish[3].setName("A Puffer fish, ochinchin no daisuki!");
	_commonFish[3].setExpReceived(0.1);
	_commonFish[3].setGoldValue(25);

	//poisson 5
	_commonFish[4].setFishTexture("C.Salmon.png");
	_commonFish[4].setName("A Salmon.. boring..");
	_commonFish[4].setExpReceived(0.1);
	_commonFish[4].setGoldValue(25);

	//poisson 6
	_commonFish[5].setFishTexture("C.Sunfish.png");
	_commonFish[5].setName("A Sunfish, holy cannoli pepperoni!");
	_commonFish[5].setExpReceived(0.1);
	_commonFish[5].setGoldValue(25);

	//poisson 7
	_commonFish[6].setFishTexture("C.Walleye.png");
	_commonFish[6].setName("A Walleye, cool!");
	_commonFish[6].setExpReceived(0.1);
	_commonFish[6].setGoldValue(25);

	_name.setFont(_textFont);
}

Fish& CommonFish::returnFish(int fishValue)
{
	return _commonFish[fishValue];
}

