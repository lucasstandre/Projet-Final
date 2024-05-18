#pragma once

#include"Fish.h"
#include<iostream>

class RareFish : public Fish
{
protected:
	Fish _rareFish[5];
public:
	void initialise();

	Fish& returnFish(int fishValue);
};

