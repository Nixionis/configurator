#pragma once

#include "GraphicsCard.h"
#include "Motherboard.h"
#include "Processor.h"
#include "RAM.h"

class Sborka
{
	GraphicsCard _card;
	Motherboard _mother;
	Processor _prots;
	RAM _ram;

	int _cost = 0;

public:

	void SetConfig(GraphicsCard card, Motherboard mother, Processor prots, RAM ram);

	GraphicsCard GetCard();

	Motherboard GetMother();

	Processor GetProts();

	RAM GetRam();

	int GetCost();
};

