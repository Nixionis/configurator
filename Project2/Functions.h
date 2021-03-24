#pragma once

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

	card.SetData("Gtx 650 ti", 10, 3000);
	cards.push_back(card);

	card.SetData("Gtx 750 ti", 20, 3900);
	cards.push_back(card);

	card.SetData("Gtx 1050 ti", 30, 11000);
	cards.push_back(card);

	card.SetData("Gtx 1070 ti", 40, 23000);
	cards.push_back(card);

	return cards;
}

std::vector<Motherboard> LoadMothersData()
{
	std::vector<Motherboard> mothers;
	Motherboard mother;

	mother.SetData("Gigabyte B365M", 10, 40, 3500, 1, 1151);
	mothers.push_back(mother);

	mother.SetData("Huananzhi B85", 10, 40, 4000, 2, 1150);
	mothers.push_back(mother);

	mother.SetData("Huananzhi B87", 10, 40, 3800, 1, 1155);
	mothers.push_back(mother);

	return mothers;
}

std::vector<Processor> LoadProcData()
{
	std::vector<Processor> procs;

	Processor proc;

	proc.SetData("Celeron Skylake", 10, 4400, 1151);
	procs.push_back(proc);

	proc.SetData("Core i5-4570", 20, 5100, 1150);
	procs.push_back(proc);

	proc.SetData("Core i7-3770", 30, 7400, 1155);
	procs.push_back(proc);

	proc.SetData("Core i7-3770K", 40, 9800, 1155);
	procs.push_back(proc);

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
	if (sb.GetCost() >= mincost && sb.GetCost() <= maxcost) Sborochki.push_back(sb);
	//if (Sborochki[0].GetCost() >= mincost && Sborochki[0].GetCost() <= maxcost) return Sborochki;
	//else
	//{
	//	//delete[] sborka;
	//	//sborka = NULL;
	//	Sborochki.clear();
	//	return Sborochki;
	//}

	point = 10 * multiplier * configtype - 10;
	if (point >= 10)
	{
		//GraphicsCard card;
		//Processor proces;
		//Motherboard mother;

		b = 0;
		e = cards.size();

		size = e;

		//Graphics

		while (b < e)
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
		ip = b;
		proces = process[b];

		//Materinka

		b = 0;
		e = mothers.size();

		for (; mothers[b].GetSocket() != process[ip].GetSocket(); b++);

		mother = mothers[b];


		//std::vector<Sborka> Sborochki;
		//Sborka sb;

		//mother = &mothers[rand() % sizeof(mothers)-1];
		sb.SetConfig(card, mother, proces);

		//sborka = new Sborka[1];

		//sborka[0].SetConfig(&cards[b]);


		//sborka[0].SetConfig(card, mother);

		if (sb.GetCost() >= mincost && sb.GetCost() <= maxcost) Sborochki.push_back(sb);
		//if (Sborochki[0].GetCost() >= mincost && Sborochki[0].GetCost() <= maxcost) return Sborochki;
		//else
		//{
		//	//delete[] sborka;
		//	//sborka = NULL;
		//	Sborochki.clear();
		//	return Sborochki;
		//}
	}

	point = 10 * multiplier * configtype+10;

	//GraphicsCard card;
	//Processor proces;
	//Motherboard mother;
	if (point <= 40)
	{
		b = 0;
		e = cards.size();

		size = e;

		//Graphics

		while (b < e)
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
		ip = b;
		proces = process[b];

		//Materinka

		b = 0;
		e = mothers.size();

		for (; mothers[b].GetSocket() != process[ip].GetSocket(); b++);

		mother = mothers[b];


		//std::vector<Sborka> Sborochki;
		//Sborka sb;

		//mother = &mothers[rand() % sizeof(mothers)-1];
		sb.SetConfig(card, mother, proces);

		//sborka = new Sborka[1];

		//sborka[0].SetConfig(&cards[b]);


		//sborka[0].SetConfig(card, mother);

		if (sb.GetCost() >= mincost && sb.GetCost() <= maxcost) Sborochki.push_back(sb);
	}
	//if (Sborochki[0].GetCost() >= mincost && Sborochki[0].GetCost() <= maxcost) return Sborochki;
	//else
	//{
	//	//delete[] sborka;
	//	//sborka = NULL;
	//	Sborochki.clear();
	//	return Sborochki;
	//}

	return Sborochki;
}