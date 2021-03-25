#include "Sborka.h"

void Sborka::SetConfig(GraphicsCard card, Motherboard mother, Processor prots, RAM ram)
{
	_card = card;
	_mother = mother;
	_prots = prots;
	_ram = ram;

	_cost = 0;
	_cost += card.GetCost();
	_cost += mother.GetCost();
	_cost += prots.GetCost();
	_cost += ram.GetCost();
}

GraphicsCard Sborka::GetCard()
{
	return _card;
}

Motherboard Sborka::GetMother()
{
	return _mother;
}

Processor Sborka::GetProts()
{
	return _prots;
}

RAM Sborka::GetRam()
{
	return _ram;
}

int Sborka::GetCost()
{
	return _cost;
}
