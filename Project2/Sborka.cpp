#include "Sborka.h"

void Sborka::SetConfig(GraphicsCard* card)
{
	_card = card;
}

GraphicsCard Sborka::GetCard()
{
	return *_card;
}

int Sborka::GetCost()
{
	return _cost;
}
