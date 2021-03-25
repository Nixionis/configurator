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

	card.SetData("Gtx 650", 10, 2500, 65);
	cards.push_back(card);

	card.SetData("Gtx 650 ti", 20, 3500, 110);
	cards.push_back(card);

	card.SetData("Gtx 750 ti", 30, 5000, 75);
	cards.push_back(card);

	card.SetData("Gtx 950", 40, 9000, 90);
	cards.push_back(card);

	card.SetData("Gtx 1050 ti", 50, 11000, 70);
	cards.push_back(card);

	card.SetData("Gtx 1060 3gb", 60, 13000, 120);
	cards.push_back(card);

	card.SetData("Gtx 1660", 70, 25000, 120);
	cards.push_back(card);

	card.SetData("Gtx 1070 ti", 80, 35000, 180);
	cards.push_back(card);

	card.SetData("RTX 3060", 90, 65000, 170);
	cards.push_back(card);

	card.SetData("RTX 3060 ti", 100, 80000, 200);
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

	proc.SetData("Core i3-6100", 20, 8500, 1151, 51);
	procs.push_back(proc);

	proc.SetData("Core i5-4570", 30, 13000, 1150, 84);
	procs.push_back(proc);

	proc.SetData("Core i5-6600", 40, 16000, 1151, 65);
	procs.push_back(proc);

	proc.SetData("Core i7-3770K", 50, 20000, 1155, 77);
	procs.push_back(proc);

	proc.SetData("Core i7-6700", 60, 25000, 1151, 65);
	procs.push_back(proc);

	proc.SetData("Core i7-8700", 80, 28000, 1151, 65);
	procs.push_back(proc);

	proc.SetData("Core i9-9900", 90, 33000, 1151, 65);
	procs.push_back(proc);

	proc.SetData("Core i9-10850K", 100, 39000, 1151, 125);
	procs.push_back(proc);

	return procs;
}

std::vector<Sborka> CreateConfigas(int configtype,int mincost, int maxcost, std::vector<GraphicsCard> cards, std::vector<Motherboard> mothers, std::vector<Processor> process)
{
	srand(time(NULL));

	float point;

	if (configtype == 1) point = 50;
	else if (configtype == 2) point = 70;
	else if (configtype == 3) point = 90;
	else point = 100;

	GraphicsCard card;
	Processor proces;
	Motherboard mother;

	std::vector<Sborka> Sborochki;

	for (int i = 0; i < 5; i++)
	{
		int pp = point - i * 10;

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
	

	return Sborochki;
}