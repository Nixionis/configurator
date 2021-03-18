#pragma once

#include <fstream>
#include "GraphicsCard.h"

void LoadFileData(GraphicsCard *cards)
{
	
	int _amount = 0;

	std::ifstream _datafile;

	_datafile.open("Graphics.txt");

	//To do: Set Error on file open here

	_datafile >> _amount;

	cards = new GraphicsCard[_amount];

	for (int _i = 0; _i < _amount; _i++)
	{
		std::string _name;
		int _point;
		int _cost;

		_datafile >> _name;
		_datafile >> _point;
		_datafile >> _cost;
		 
		cards[_i].SetData(_name, _point, _cost);
	}
}

void CreateConfigs(float multiplier, int configtype)
{

}