#pragma once

#include<iostream>

class Motherboard
{
private:
	std::string _mothername;
	int _minpoints, _maxpoints, _cost, _size, _socket;

public:
	void SetData(std::string name, int minpoints, int maxpoints, int cost, int size, int socket);

	std::string GetName();

	int GetMinPoints();

	int GetMaxPoints();

	int GetCost();

	int GetSize();

	int GetSocket();
};

