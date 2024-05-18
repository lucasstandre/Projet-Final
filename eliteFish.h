#pragma once

#include"Fish.h"
#include<iostream>

class EliteFish : public Fish
{
protected:
	Fish _eliteFish[2];
public:
	void initialise();

	Fish& returnFish(int fishValue);
};

