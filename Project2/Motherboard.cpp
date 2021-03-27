#include "Motherboard.h"

void Motherboard::SetData(std::string name, int minpoints, int maxpoints, int cost, int size, int socket)
{
	_mothername = name;
	for (int i = 0; i < _mothername.size(); i++)
		if (_mothername[i] == 95)	_mothername[i] = ' ';

	_minpoints = minpoints;
	_maxpoints = maxpoints;
	_cost = cost;
	_size = size;
	_socket = socket;
}

std::string Motherboard::GetName()
{
	return _mothername;
}

int Motherboard::GetMinPoints()
{
	return _minpoints;
}

int Motherboard::GetMaxPoints()
{
	return _maxpoints;
}

int Motherboard::GetCost()
{
	return _cost;
}

int Motherboard::GetSize()
{
	return _size;
}

int Motherboard::GetSocket()
{
	return _socket;
}
