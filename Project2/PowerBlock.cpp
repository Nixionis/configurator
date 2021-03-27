#include "PowerBlock.h"

void PowerBlock::SetData(std::string name, int watt, int cost)
{
	_blockname = name;
	for (int i = 0; i < _blockname.size(); i++)
		if (_blockname[i] == 95) _blockname[i] = ' ';

	_watt = watt;
	_cost = cost;
}

std::string PowerBlock::GetName()
{
	return _blockname;
}

int PowerBlock::GetWatt()
{
	return _watt;
}

int PowerBlock::GetCost()
{
	return _cost;
}
