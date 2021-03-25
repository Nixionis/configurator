#pragma once

#include <ctime>
#include <vector>
#include "GraphicsCard.h"
#include "Motherboard.h"
#include "Processor.h"
#include "RAM.h"
#include "Sborka.h"

std::vector<GraphicsCard> LoadGraphicsData()
{
	std::vector<GraphicsCard> cards;

	GraphicsCard card;

	card.SetData("Gtx 650", 5, 2500, 65);
	cards.push_back(card);

	card.SetData("Gtx 650 ti", 10, 3500, 110);
	cards.push_back(card);

	card.SetData("Gtx 750 ti", 15, 5000, 75);
	cards.push_back(card);

	card.SetData("Gtx 950", 20, 9000, 90);
	cards.push_back(card);

	card.SetData("Gtx 1050 ti", 25, 11000, 70);
	cards.push_back(card);

	card.SetData("Gtx 1060 3gb", 30, 13000, 120);
	cards.push_back(card);

	card.SetData("Gtx 1660", 35, 25000, 120);
	cards.push_back(card);

	card.SetData("Gtx 1070 ti", 40, 35000, 180);
	cards.push_back(card);

	card.SetData("RTX 3060", 45, 65000, 170);
	cards.push_back(card);

	card.SetData("RTX 3060 ti", 50, 80000, 200);
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

	proc.SetData("Core i3-4340", 10, 7000, 1150, 54);
	procs.push_back(proc);

	proc.SetData("Core i3-6100", 15, 8500, 1151, 51);
	procs.push_back(proc);

	proc.SetData("Core i5-4570", 20, 13000, 1150, 84);
	procs.push_back(proc);

	proc.SetData("Core i5-6600", 25, 16000, 1151, 65);
	procs.push_back(proc);

	proc.SetData("Core i7-3770K", 30, 20000, 1155, 77);
	procs.push_back(proc);

	proc.SetData("Core i7-6700", 35, 25000, 1151, 65);
	procs.push_back(proc);

	proc.SetData("Core i7-8700", 40, 28000, 1151, 65);
	procs.push_back(proc);

	proc.SetData("Core i9-9900", 45, 33000, 1151, 65);
	procs.push_back(proc);

	proc.SetData("Core i9-10850K", 50, 39000, 1151, 125);
	procs.push_back(proc);

	return procs;
}

std::vector<RAM> LoadRAMData()
{
	std::vector<RAM> RAMS;

	RAM ramka;

	ramka.
}

std::vector<Sborka> CreateConfigas(float multiplier, int configtype,int mincost, int maxcost, std::vector<GraphicsCard> cards, std::vector<Motherboard> mothers, std::vector<Processor> process)
{
	srand(time(NULL));

	float point;

	if (configtype == 1) point = 25;
	else if (configtype == 2) point = 35;
	else if (configtype == 3) point = 45;
	else point = 50;

	GraphicsCard card;
	Processor proces;
	Motherboard mother;

	std::vector<Sborka> Sborochki;

	for (int i = 0; i < 5; i++)
	{
		int pp = point - i * 5;

		int b = 0;
		int e = cards.size();

		int size = e;

		//Graphics

		while (b < e)
		{
			int c = (b + e) / 2;

			if (cards[c].GetPoints() < (int)pp) b = c + 1;
			else e = c;
		}
		card = cards[b];

		//Processors

		b = 0;
		e = process.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (process[c].GetPoints() < (int)pp) b = c + 1;
			else e = c;
		}
		int ip = b;
		proces = process[b];

		//Materinka

		b = 0;
		e = mothers.size();

		for (; mothers[b].GetSocket() != process[ip].GetSocket(); b++);

		mother = mothers[b];


		Sborka sb;

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

	//point = 10 * multiplier * configtype - 10;
	//if (point >= 10)
	//{
		//GraphicsCard card;
		//Processor proces;
		//Motherboard mother;

	//	b = 0;
	//	e = cards.size();

	//	size = e;

		//Graphics

	//	while (b < e)
	//	{
	//		int c = (b + e) / 2;

	//		if (cards[c].GetPoints() < (int)point) b = c + 1;
	//		else e = c;
	//	}
	//	card = cards[b];

		//Processors

	//	b = 0;
	//	e = process.size();

	//	while (b < e)
	//	{
	//		int c = (b + e) / 2;

	//		if (process[c].GetPoints() < (int)point) b = c + 1;
	//		else e = c;
	//	}
	//	ip = b;
	//	proces = process[b];

		//Materinka

	//	b = 0;
	//	e = mothers.size();

	//	for (; mothers[b].GetSocket() != process[ip].GetSocket(); b++);

	//	mother = mothers[b];


		//std::vector<Sborka> Sborochki;
		//Sborka sb;

		//mother = &mothers[rand() % sizeof(mothers)-1];
	//	sb.SetConfig(card, mother, proces);

		//sborka = new Sborka[1];

		//sborka[0].SetConfig(&cards[b]);


		//sborka[0].SetConfig(card, mother);

	//	if (sb.GetCost() >= mincost && sb.GetCost() <= maxcost) Sborochki.push_back(sb);
		//if (Sborochki[0].GetCost() >= mincost && Sborochki[0].GetCost() <= maxcost) return Sborochki;
		//else
		//{
		//	//delete[] sborka;
		//	//sborka = NULL;
		//	Sborochki.clear();
		//	return Sborochki;
		//}
	//}

	//point = 10 * multiplier * configtype+10;

	//GraphicsCard card;
	//Processor proces;
	//Motherboard mother;
//	if (point <= 40)
//	{
	//	b = 0;
	//	e = cards.size();

	//	size = e;

		//Graphics

	//	while (b < e)
	//	{
	//		int c = (b + e) / 2;

	//		if (cards[c].GetPoints() < (int)point) b = c + 1;
	//		else e = c;
	//	}
	//	card = cards[b];

		//Processors

	//	b = 0;
	//	e = process.size();

	//	while (b < e)
	//	{
	//		int c = (b + e) / 2;

	//		if (process[c].GetPoints() < (int)point) b = c + 1;
	//		else e = c;
	//	}
	//	ip = b;
	//	proces = process[b];

		//Materinka

	//	b = 0;
	//	e = mothers.size();

	//	for (; mothers[b].GetSocket() != process[ip].GetSocket(); b++);

	//	mother = mothers[b];


		//std::vector<Sborka> Sborochki;
		//Sborka sb;

		//mother = &mothers[rand() % sizeof(mothers)-1];
	//	sb.SetConfig(card, mother, proces);

		//sborka = new Sborka[1];

		//sborka[0].SetConfig(&cards[b]);


		//sborka[0].SetConfig(card, mother);

	//	if (sb.GetCost() >= mincost && sb.GetCost() <= maxcost) Sborochki.push_back(sb);
	//}
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