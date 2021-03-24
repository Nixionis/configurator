#include "GraphicsCard.h"

//GraphicsCard::GraphicsCard()
//{
//	_cardname = NULL;
//	_points = NULL;
//	_cost = NULL;
//}

void GraphicsCard::SetData(std::string name, int points, int cost, int tdp)
{
	//_cardname = new std::string;
	_cardname = name;

	//_points = new int;
	_points = points;

	//_cost = new int;
	_cost = cost;

	_tdp = tdp;
};

//GraphicsCard::~GraphicsCard()
//{
//	delete _cardname;
//	delete _points;
//	delete _cost;
//};

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
