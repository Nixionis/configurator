#pragma once

#include <fstream>
#include "GraphicsCard.h"
#include "Sborka.h"

GraphicsCard* LoadFileData(GraphicsCard *cards)
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
	return cards;
}

Sborka* CreateConfigas(float multiplier, int configtype,int mincost, int maxcost,  Sborka* sborka, GraphicsCard *cards)
{
	float point = 10*multiplier*configtype;

	int b = 0;
	int e = sizeof(cards)-1;
	

	int size = e;
	//int cur = c;

	while (b<e)
	{
		int c = (b + e) / 2;
		
	    if (cards[c].GetPoints() < (int)point) b = c + 1;
		else e = c;
	}

	if (cards[b].GetCost() >= mincost && cards[b].GetCost() <= maxcost)
	{
		sborka = new Sborka[1];
		sborka[0].SetConfig(&cards[b]);
	}
	else return sborka;
	
	return sborka;
}