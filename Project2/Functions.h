#pragma once

#include <fstream>
#include <ctime>
#include <vector>
#include "GraphicsCard.h"
#include "Motherboard.h"
#include "Processor.h"
#include "Sborka.h"

std::vector<GraphicsCard> LoadGraphicsData()
{
	std::vector<GraphicsCard> cards;

	GraphicsCard card;

	int _amount = 0;

	std::ifstream _datafile;

	_datafile.open("Graphics.txt");

	////To do: Set Error on file open here

	_datafile >> _amount;

	for (int _i = 0; _i < _amount; _i++)
	{
		std::string _name;
		int _point;
		int _cost;

		_datafile >> _name;
		_datafile >> _point;
		_datafile >> _cost;
		 
		card.SetData(_name, _point, _cost);
		cards.push_back(card);
	}

	_datafile.close();
	return cards;
}

std::vector<Motherboard> LoadMothersData()
{
	std::vector<Motherboard> mothers;
	Motherboard mother;

	int _amount = 0;

	std::ifstream _datafile;

	_datafile.open("Mothers.txt");

	//To do: Set Error on file open here

	_datafile >> _amount;

	//mothers = new Motherboard[_amount];

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

		mother.SetData(_name, _minpoint, _maxpoint, _cost, _size, _socket);
		mothers.push_back(mother);

		//mothers[_i].SetData(_name, _minpoint, _maxpoint, _cost, _size, _socket);
	}

	_datafile.close();
	return mothers;
}

std::vector<Processor> LoadProcData()
{
	std::vector<Processor> procs;

	Processor proc;

	int _amount = 0;

	std::ifstream _datafile;

	_datafile.open("Procc.txt");

	////To do: Set Error on file open here

	_datafile >> _amount;

	for (int _i = 0; _i < _amount; _i++)
	{
		std::string _name;
		int _point;
		int _cost;
		int _socket;

		_datafile >> _name;
		_datafile >> _point;
		_datafile >> _cost;
		_datafile >> _socket;

		proc.SetData(_name, _point, _cost, _socket);
		procs.push_back(proc);
	}

	_datafile.close();
	return procs;
}

std::vector<Sborka> CreateConfigas(float multiplier, int configtype,int mincost, int maxcost, std::vector<GraphicsCard> cards, std::vector<Motherboard> mothers, std::vector<Processor> process)
{
	srand(time(NULL));
	float point = 10*multiplier*configtype;

	GraphicsCard card;
	Processor proces;
	Motherboard mother;

	int b = 0;
	int e = cards.size();
	

	int size = e;
	
	//Graphics

	while (b<e)
	{
		int c = (b + e) / 2;
		
	    if (cards[c].GetPoints() < (int)point) b = c + 1;
		else e = c;
	}
	card = cards[b];

	//Processors

	b = 0;
	e = process.size();

	while (b < e)
	{
		int c = (b + e) / 2;

		if (process[c].GetPoints() < (int)point) b = c + 1;
		else e = c;
	}
	int ip = b;
	proces = process[b];

	//Materinka

	b = 0;
	e = mothers.size();

	for (; mothers[b].GetSocket() != process[ip].GetSocket(); b++);

	mother = mothers[b];


	std::vector<Sborka> Sborochki;
	Sborka sb;
	
	//mother = &mothers[rand() % sizeof(mothers)-1];
	sb.SetConfig(card, mother, proces);
	
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