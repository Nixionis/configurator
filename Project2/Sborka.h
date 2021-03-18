#pragma once

#include "GraphicsCard.h"

class Sborka
{
	GraphicsCard *_card;
	int _cost = 0;

public:

	void SetConfig(GraphicsCard* card);

	GraphicsCard GetCard();

	int GetCost();
};

