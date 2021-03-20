#include "Processor.h"

void Processor::SetData(std::string name, int points, int cost, int socket)
{
	_procname = name;
	_points = points;
	_cost = cost;
	_socket = socket;
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
