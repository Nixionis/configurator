#pragma once

#include<iostream>

class PowerBlock
{
private:
	std::string _blockname;
	int _watt, _cost;

public:

	void SetData(std::string name, int watt, int cost);

	std::string GetName();

	int GetWatt();

	int GetCost();

};

