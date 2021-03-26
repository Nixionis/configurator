#include "PowerBlock.h"

void PowerBlock::SetData(std::string name, int watt, int cost)
{
	_blockname = name;
	_watt = watt;
	_cost = cost;
}

std::string PowerBlock::GetName()
{
	return _blockname;
}

int PowerBlock::GetPoints()
{
	return _watt;
}

int PowerBlock::GetCost()
{
	return _cost;
}
