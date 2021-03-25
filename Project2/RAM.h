#pragma once

#include <iostream>

class RAM
{
	std::string _ramname;
	int _points, _cost;// , _socket, _tdp;

public:

	void SetData(std::string name, int points, int cost);//, int socket, int tdp);

	std::string GetName();

	int GetPoints();

	int GetCost();

	//int GetSocket();

	//int GetTdp(); 
};

