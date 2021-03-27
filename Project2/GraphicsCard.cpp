#include "GraphicsCard.h"

void GraphicsCard::SetData(std::string name, int points, int cost, int tdp)
{	
	_cardname = name;
	for (int i = 0; i < _cardname.size(); i++)
		if (_cardname[i] == 95)	_cardname[i] = ' ';
		
	_points = points;

	_cost = cost;

	_tdp = tdp;
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
}
int GraphicsCard::GetTdp()
{
	return _tdp;
}
;
