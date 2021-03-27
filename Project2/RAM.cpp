#include "RAM.h"

void RAM::SetData(std::string name, int gb, int cost)
{
	_ramname = name;
	for (int i = 0; i < _ramname.size(); i++)
		if (_ramname[i] == 95)	_ramname[i] = ' ';

	_GB = gb;
	_cost = cost;
}

std::string RAM::GetName()
{
	return _ramname;
}

int RAM::GetGB()
{
	return _GB;
}

int RAM::GetCost()
{
	return _cost;
}
