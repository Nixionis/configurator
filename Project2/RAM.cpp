#include "RAM.h"

void RAM::SetData(std::string name, int points, int cost)
{
	_ramname = name;
	_points = points;
	_cost = cost;
}

std::string RAM::GetName()
{
	return _ramname;
}

int RAM::GetPoints()
{
	return _points;
}

int RAM::GetCost()
{
	return _cost;
}
