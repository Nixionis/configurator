#pragma once

#include <ctime>
#include <vector>
#include "GraphicsCard.h"
#include "Motherboard.h"
#include "Processor.h"
#include "RAM.h"
#include "SATA.h"
#include "PowerBlock.h"
#include "Sborka.h"

std::vector<GraphicsCard> LoadGraphicsData()
{
	//Загрузка в базу данных графических карт
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
	//Загрузка в базу данных материнских карт
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
	//Загрузка в базу данных процессоров
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

std::vector<RAM> LoadRAMData()
{
	//Загрузка в базу данных оперативной памяти
	std::vector<RAM> RAMS;

	RAM ramka;

	ramka.SetData("RAM 4 GB", 10, 1800);
	RAMS.push_back(ramka);

	ramka.SetData("RAM 4 GB", 20, 1800);
	RAMS.push_back(ramka);

	ramka.SetData("RAM 8 GB", 30, 3500);
	RAMS.push_back(ramka);

	ramka.SetData("RAM 8 GB", 40, 3500);
	RAMS.push_back(ramka);

	ramka.SetData("RAM 8 GB", 50, 3500);
	RAMS.push_back(ramka);

	ramka.SetData("RAM 16 GB", 60, 8500);
	RAMS.push_back(ramka);

	ramka.SetData("RAM 16 GB", 70, 8500);
	RAMS.push_back(ramka);

	ramka.SetData("RAM 16 GB", 80, 8500);
	RAMS.push_back(ramka);

	ramka.SetData("RAM 32 GB", 90, 16500);
	RAMS.push_back(ramka);

	ramka.SetData("RAM 32 GB", 100, 16500);
	RAMS.push_back(ramka);

	return RAMS;
}

std::vector<SATA> LoadSATAData()
{
	//Загрузка в базу данных жестких дисков
	std::vector<SATA> SATS;

	SATA sata;

	sata.SetData("HDD 256 GB", 10, 1200);
	SATS.push_back(sata);

	sata.SetData("HDD 512 GB", 20, 1800);
	SATS.push_back(sata);

	sata.SetData("HDD 512 GB", 30, 1800);
	SATS.push_back(sata);

	sata.SetData("HDD 1024 GB", 40, 2800);
	SATS.push_back(sata);

	sata.SetData("HDD 1024 GB + SSD 128 GB", 50, 3800);
	SATS.push_back(sata);

	sata.SetData("SSD 256 GB", 60, 3200);
	SATS.push_back(sata);

	sata.SetData("SSD 512 GB", 70, 4800);
	SATS.push_back(sata);

	sata.SetData("SSD 512 GB", 80, 4800);
	SATS.push_back(sata);

	sata.SetData("SSD 1024 GB", 90, 8900);
	SATS.push_back(sata);

	sata.SetData("SSD 1024 GB", 100, 8900);
	SATS.push_back(sata);

	return SATS;
}

std::vector<PowerBlock> LoadPowerData()
{
	//Загрузка в базу данных жестких дисков
	std::vector<PowerBlock> Powers;

	PowerBlock power;

	power.SetData("Aerocool VX PLUS 350W", 350, 1500);
	Powers.push_back(power);

	power.SetData("Aerocool ECO 500W", 500, 2000);
	Powers.push_back(power);

	power.SetData("Aerocool VX PLUS 600W", 600, 2550);
	Powers.push_back(power);

	power.SetData("Xilence XN054 700W", 700, 3000);
	Powers.push_back(power);

	return Powers;
}

std::vector<Sborka> CreateConfigas(int configtype,int mincost, int maxcost, std::vector<GraphicsCard> cards, 
std::vector<Motherboard> mothers, std::vector<Processor> process, std::vector<RAM> rams, std::vector<SATA> sats, std::vector<PowerBlock> powers)
{
	//Генерация сборок
	//Сид рандома
	srand(time(NULL));

	float point;
	//Очки мощности от типа
	if (configtype == 1) point = 50;
	else if (configtype == 2) point = 70;
	else if (configtype == 3) point = 90;
	else point = 100;
	//Для хранения временных выборов
	GraphicsCard card;
	Processor proces;
	Motherboard mother;
	RAM ram;
	SATA sata;
	PowerBlock power;

	int tdp = 0;
	//Вектора сборок
	std::vector<Sborka> Sborochki;
	//Генерация 5 (i) сборок
	for (int i = 0; i < 5; i++)
	{
		tdp = 0;
		//Очки мощности от максимальной мощности до низкой в данной категории
		int pp = point - i * 10;
		//Дихтомический поиск графической карты
		int b = 0;
		int e = cards.size();

		int size = e;

		while (b < e)
		{
			int c = (b + e) / 2;
			//Поиск сопоставимой по мощности
			if (cards[c].GetPoints() < (int)pp) b = c + 1;
			else e = c;
		}
		card = cards[b];
		tdp += card.GetTdp();

		//Поиск процессора по мощности

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
		tdp += proces.GetTdp() + 200;

		//Поиск материнской карты по сокету процессора

		b = 0;
		e = mothers.size();

		for (; mothers[b].GetSocket() != process[ip].GetSocket(); b++);

		mother = mothers[b];

		//Поиск оперативной памяти по мощности
		
		b = 0;
		e = rams.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (rams[c].GetPoints() < (int)pp) b = c + 1;
			else e = c;
		}

		ram = rams[b];
		
		//Поиск жесткого диска по мощности

		b = 0;
		e = sats.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (sats[c].GetPoints() < (int)pp) b = c + 1;
			else e = c;
		}

		sata = sats[b];

		//Поиск блока питания по мощности

		b = 0;
		e = powers.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (powers[c].GetPoints() < (int)tdp) b = c + 1;
			else e = c;
		}

		power = powers[b];

		//Сбор всех найденных компонентов в сборку

		Sborka sb;
		sb.SetConfig(card, mother, proces, ram, sata, power);

		//Сравнение цены сборки с рамками бюджета

		if (sb.GetCost() >= mincost && sb.GetCost() <= maxcost) Sborochki.push_back(sb);
	}

	return Sborochki;
}