#include "Sborka.h"

void Sborka::SetConfig(GraphicsCard card, Motherboard mother, Processor prots)
{
	_card = card;
	_mother = mother;
	_prots = prots;

	_cost = 0;
	_cost += card.GetCost();
	_cost += mother.GetCost();
	_cost += prots.GetCost();
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

int Sborka::GetCost()
{
	return _cost;
}
