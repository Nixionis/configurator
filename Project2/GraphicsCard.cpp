#include "GraphicsCard.h"

void GraphicsCard::SetData(std::string name, int points, int cost)
{
	_cardname = name;
	_points = points;
	_cost = cost;
};

std::string GraphicsCard::GetName()
{
	return _cardname;
};

int GraphicsCard::GetPoints()
{
	return _points;
};

int GraphicsCard::GetCost()
{
	return _cost;
};
