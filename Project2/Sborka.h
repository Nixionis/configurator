#pragma once

#include "GraphicsCard.h"
#include "Motherboard.h"

class Sborka
{
	GraphicsCard* _card;
	Motherboard* _mother;

	int _cost = 0;

public:

	void SetConfig(GraphicsCard* card, Motherboard* mother);

	GraphicsCard GetCard();

	Motherboard GetMother();

	int GetCost();
};

