#include "SATA.h"

void SATA::SetData(std::string name, int gb, int type, int cost)
{
	_sataname = name;
	for (int i = 0; i < _sataname.size(); i++)
		if (_sataname[i] == 95)	_sataname[i] = ' ';

	_GB = gb;
	_type = type;
	_cost = cost;
}

std::string SATA::GetName()
{
	return _sataname;
}

int SATA::GetGB()
{
	return _GB;
}

int SATA::GetType()
{
	return _type;
}

int SATA::GetCost()
{
	return _cost;
}
