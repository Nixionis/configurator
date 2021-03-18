#include "Sborka.h"

void Sborka::SetConfig(GraphicsCard* card, Motherboard* mother)
{
	_card = card;
	_mother = mother;

	_cost = 0;
	_cost += card->GetCost();
	_cost += mother->GetCost();
}

GraphicsCard Sborka::GetCard()
{
	return *_card;
}

Motherboard Sborka::GetMother()
{
	return *_mother;
}

int Sborka::GetCost()
{
	return _cost;
}
