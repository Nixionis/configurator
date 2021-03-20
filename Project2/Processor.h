#pragma once

#include<iostream>

class Processor
{
	std::string _procname;
	int _points, _cost, _socket;

public:

	void SetData(std::string name, int points, int cost, int socket);

	std::string GetName();

	int GetPoints();

	int GetCost();

	int GetSocket();
};

