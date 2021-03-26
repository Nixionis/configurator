#pragma once

#include<iostream>

class GraphicsCard
{
private:
	std::string _cardname;
	int _points, _cost, _tdp;

public:

	void SetData(std::string name, int points, int cost, int tdp);

	std::string GetName();

	int GetPoints();

	int GetCost();

	int GetTdp();
};

