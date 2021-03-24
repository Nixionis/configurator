#include "Processor.h"

void Processor::SetData(std::string name, int points, int cost, int socket, int tdp)
{
	_procname = name;
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
