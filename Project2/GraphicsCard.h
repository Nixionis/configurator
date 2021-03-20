#pragma once

#include<iostream>

class GraphicsCard
{
private:
	std::string _cardname;
	int _points, _cost;

public:

	//GraphicsCard();

	void SetData(std::string name, int points, int cost);

	//~GraphicsCard();

	std::string GetName();

	int GetPoints();

	int GetCost();
};

