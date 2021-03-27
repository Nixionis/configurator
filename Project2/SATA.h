#pragma once

#include<iostream>

class SATA
{
private:
	std::string _sataname;
	int _GB, _type, _cost;

public:

	void SetData(std::string name, int gb, int type, int cost);

	std::string GetName();

	int GetGB();

	int GetType();

	int GetCost();

};

