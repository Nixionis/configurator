#pragma once

#include<iostream>

class SATA
{
private:
	std::string _cardname;
	int _points, _cost;

public:

	void SetData(std::string name, int points, int cost);

	std::string GetName();

	int GetPoints();

	int GetCost();

};

