#pragma once

#include "GraphicsCard.h"
#include "Motherboard.h"
#include "Processor.h"

class Sborka
{
	GraphicsCard _card;
	Motherboard _mother;
	Processor _prots;

	int _cost = 0;

public:

	void SetConfig(GraphicsCard card, Motherboard mother, Processor prots);

	GraphicsCard GetCard();

	Motherboard GetMother();

	Processor GetProts();

	int GetCost();
};

