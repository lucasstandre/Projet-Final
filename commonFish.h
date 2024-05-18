#pragma once

#include"Fish.h"
#include<iostream>

class CommonFish : public Fish
{
protected:
	Fish _commonFish[7];
public:
	void initialise();

	Fish& returnFish(int fishValue);

};

