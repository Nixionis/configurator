#pragma once

#include "GraphicsCard.h"
#include "Motherboard.h"
#include "Processor.h"
#include "RAM.h"
#include "SATA.h"
#include "PowerBlock.h"

class Sborka
{
	GraphicsCard _card;
	Motherboard _mother;
	Processor _prots;
	RAM _ram;
	SATA _sata;
	PowerBlock _power;

	int _cost = 0;

public:

	void SetConfig(GraphicsCard card, Motherboard mother, Processor prots, RAM ram, SATA sata, PowerBlock power);

	GraphicsCard GetCard();

	Motherboard GetMother();

	Processor GetProts();

	RAM GetRam();

	SATA GetSata();

	PowerBlock GetPower();

	int GetCost();

	bool operator==(Sborka DifSborka);

	bool operator<(Sborka DifSborka);
};

