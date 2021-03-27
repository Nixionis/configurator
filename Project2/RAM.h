#pragma once

#include <iostream>

class RAM
{
	std::string _ramname;
	int _GB, _cost;

public:

	void SetData(std::string name, int gb, int cost);

	std::string GetName();

	int GetGB();

	int GetCost();
};

