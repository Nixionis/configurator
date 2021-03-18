#pragma once

#include <fstream>
#include <ctime>
#include <vector>
#include "GraphicsCard.h"
#include "Motherboard.h"
#include "Sborka.h"

GraphicsCard* LoadGraphicsData(GraphicsCard *cards)
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

	_datafile.close();
	return cards;
}

Motherboard* LoadMothersData(Motherboard* mothers)
{

	int _amount = 0;

	std::ifstream _datafile;

	_datafile.open("Mothers.txt");

	//To do: Set Error on file open here

	_datafile >> _amount;

	mothers = new Motherboard[_amount];

	for (int _i = 0; _i < _amount; _i++)
	{
		std::string _name;
		int _minpoint;
		int _maxpoint;
		int _cost;
		int _size;
		int _socket;

		_datafile >> _name;
		_datafile >> _minpoint;
		_datafile >> _maxpoint;
		_datafile >> _cost;
		_datafile >> _size;
		_datafile >> _socket;

		mothers[_i].SetData(_name, _minpoint, _maxpoint, _cost, _size, _socket);
	}

	_datafile.close();
	return mothers;
}

std::vector<Sborka> CreateConfigas(float multiplier, int configtype,int mincost, int maxcost,  Sborka* sborka, GraphicsCard *cards, Motherboard *mothers)
{
	srand(time(NULL));
	float point = 10*multiplier*configtype;

	GraphicsCard* card;
	Motherboard* mother;

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

	std::vector<Sborka> Sborochki;
	Sborka sb;
	card = &cards[b];
	mother = &mothers[rand() % sizeof(mothers)-1];
	sb.SetConfig(card, mother);
	
	//sborka = new Sborka[1];
	
		//sborka[0].SetConfig(&cards[b]);

	
	//sborka[0].SetConfig(card, mother);

	Sborochki.push_back(sb);
	if (Sborochki[0].GetCost() >= mincost && Sborochki[0].GetCost() <= maxcost) return Sborochki;
	else
	{
		//delete[] sborka;
		//sborka = NULL;
		Sborochki.clear();
		return Sborochki;
	}

	//return sborka;
}