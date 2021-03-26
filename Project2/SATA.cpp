#include "SATA.h"

void SATA::SetData(std::string name, int points, int cost)
{
	_cardname = name;
	_points = points;
	_cost = cost;
}

std::string SATA::GetName()
{
	return _cardname;
}

int SATA::GetPoints()
{
	return _points;
}

int SATA::GetCost()
{
	return _cost;
}
