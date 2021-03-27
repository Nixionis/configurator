#include "Processor.h"

void Processor::SetData(std::string name, int points, int cost, int socket, int tdp)
{
	_procname = name;
	for (int i = 0; i < _procname.size(); i++)
		if (_procname[i] == 95)	_procname[i] = ' ';

	_points = points;
	_cost = cost;
	_socket = socket;
	_tdp = tdp;
}

std::string Processor::GetName()
{
	return _procname;
}

int Processor::GetPoints()
{
	return _points;
}

int Processor::GetCost()
{
	return _cost;
}

int Processor::GetSocket()
{
	return _socket;
}

int Processor::GetTdp()
{
	return _tdp;
}
