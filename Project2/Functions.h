#pragma once

#include <ctime>
#include <vector>
#include <fstream>
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

	std::fstream GraphicFile("Graphics.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int power;
	int cost;
	int tdp;

	GraphicFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		GraphicFile >> name;
		GraphicFile >> power;
		GraphicFile >> cost;
		GraphicFile >> tdp;
		card.SetData(name, power, cost, tdp);
		cards.push_back(card);
	}

	return cards;
}

std::vector<Motherboard> LoadMothersData()
{
	//Загрузка в базу данных материнских карт
	std::vector<Motherboard> mothers;
	Motherboard mother;

	std::fstream MBoardFile("Mboards.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int powermin;
	int powermax;
	int cost;
	int size;
	int socket;

	MBoardFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		MBoardFile >> name;
		MBoardFile >> powermin;
		MBoardFile >> powermax;
		MBoardFile >> cost;
		MBoardFile >> size;
		MBoardFile >> socket;
		mother.SetData(name, powermin, powermax, cost, size, socket);
		mothers.push_back(mother);
	}

	return mothers;
}

std::vector<Processor> LoadProcData()
{
	//Загрузка в базу данных процессоров
	std::vector<Processor> procs;
	Processor proc;

	std::fstream ProccsFile("Proccs.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int power;
	int cost;
	int socket;
	int tdp;

	ProccsFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		ProccsFile >> name;
		ProccsFile >> power;
		ProccsFile >> cost;
		ProccsFile >> socket;
		ProccsFile >> tdp;
		proc.SetData(name, power, cost, socket, tdp);
		procs.push_back(proc);
	}

	return procs;
}

std::vector<RAM> LoadRAMData()
{
	//Загрузка в базу данных оперативной памяти
	std::vector<RAM> RAMS;
	RAM ram;

	std::fstream RAMFile("RAM.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int GBs;
	int cost;

	RAMFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		RAMFile >> name;
		RAMFile >> GBs;
		RAMFile >> cost;
		ram.SetData(name, GBs, cost);
		RAMS.push_back(ram);
	}

	return RAMS;
}

std::vector<SATA> LoadSATAData()
{
	//Загрузка в базу данных жестких дисков
	std::vector<SATA> SATS;
	SATA sata;

	std::fstream SATAFile("SATA.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int GBs;
	int type;
	int cost;

	SATAFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		SATAFile >> name;
		SATAFile >> GBs;
		SATAFile >> type;
		SATAFile >> cost;
		sata.SetData(name, GBs, type, cost);
		SATS.push_back(sata);
	}

	return SATS;
}

std::vector<PowerBlock> LoadPowerData()
{
	//Загрузка в базу данных жестких дисков
	std::vector<PowerBlock> Powers;
	PowerBlock power;

	std::fstream PowerFile("PowerBlocks.txt");

	//TODO: Open ERROR

	int amount;

	std::string name;
	int Watt;
	int cost;

	PowerFile >> amount;

	for (int i = 0; i < amount; i++)
	{
		PowerFile >> name;
		PowerFile >> Watt;
		PowerFile >> cost;
		power.SetData(name, Watt, cost);
		Powers.push_back(power);
	}

	return Powers;
}

std::vector<Sborka> CreateConfigas(int configtype,int mincost, int maxcost, std::vector<GraphicsCard> cards, 
std::vector<Motherboard> mothers, std::vector<Processor> process, std::vector<RAM> rams, std::vector<SATA> sats, std::vector<PowerBlock> powers)
{
	//Генерация сборок
	//Сид рандома

	srand(time(NULL));

	int OverallPoints = 50;
	int GrahpicPoints = 40;
	int ProccessorPoints = 40;
	int RamPoints = 8;
	int SataPoints = 512;
	int SataType = 1;

	//Очки мощности от типа
	if (configtype == 2)
	{
		OverallPoints = 70;
		GrahpicPoints = 40;
		ProccessorPoints = 60;
		RamPoints = 8;
		SataPoints = 512;
		SataType = 1;
	}
	else if (configtype == 3)
	{
		OverallPoints = 90;
		GrahpicPoints = 80;
		ProccessorPoints = 70;
		RamPoints = 16;
		SataPoints = 256;
		SataType = 2;
	}
	else  if (configtype == 4)
	{
		OverallPoints = 100;
		GrahpicPoints = 100;
		ProccessorPoints = 100;
		RamPoints = 32;
		SataPoints = 1024;
		SataType = 2;
	}

	//Минимальные границы до куда подбирать сборки

	int gpb = 0;
	int ppb = 0;
	int rpb = 4;
	int spb = 256;
	int stb = 1;

	if (configtype == 2)
	{
		gpb = 10;
		ppb = 20;
	}
	else if (configtype == 3)
	{
		gpb = 30;
		ppb = 30;
		rpb = 8;
		spb = 512;
	}
	else if (configtype == 4)
	{
		gpb = 40;
		ppb = 50;
		rpb = 8;
		spb = 512;
		stb = 2;
	}

	//Для хранения временных выборов
	GraphicsCard card;
	Processor proces;
	Motherboard mother;
	RAM ram;
	SATA sata;
	PowerBlock power;

	int tdp = 0;
	//Вектора сборок
	std::vector<Sborka> Sborki;

	//Текущие данные для циклов     общие
	int op = OverallPoints;
	int gp = GrahpicPoints;
	int pp = ProccessorPoints;
	int rp = RamPoints;
	int sp = SataPoints;
	int st = SataType;
	// текущие
	int opt = op;
	int gpt = gp;
	int ppt = pp;
	int rpt = rp;
	int spt = sp;
	int stt = st;

	//Генерация 5 (i) сборок
	for (int i = 0; i < 10; i++)
	{
		tdp = 0;
		//Дихотомический поиск графической карты
		int b = 0;
		int e = cards.size();

		int size = e;

		while (b < e)
		{
			int c = (b + e) / 2;
			//Поиск сопоставимой по мощности
			if (cards[c].GetPoints() < (int)gpt) b = c + 1;
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

			if (process[c].GetPoints() < (int)ppt) b = c + 1;
			else e = c;
		}
		int ip = b;
		proces = process[b];
		tdp += proces.GetTdp() + 175;

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

			if (rams[c].GetGB() < (int)rpt) b = c + 1;
			else e = c;
		}

		ram = rams[b];
		
		//Поиск жесткого диска по мощности

		b = 0;
		e = sats.size();
		for (int j = 0; j < e; j++)
		{
			int ss = sats[j].GetGB();
			int sss = sats[j].GetType();
			if (ss == spt && sss == stt)
			{
				b = j;
				break;
			}
		}

		sata = sats[b];

		//Поиск блока питания по мощности

		b = 0;
		e = powers.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (powers[c].GetWatt() < (int)tdp) b = c + 1;
			else e = c;
		}

		power = powers[b];

		//Сбор всех найденных компонентов в сборку

		Sborka sb;
		sb.SetConfig(card, mother, proces, ram, sata, power);

		//Сравнение цены сборки с рамками бюджета

		if (sb.GetCost() >= mincost && sb.GetCost() <= maxcost )
		{
			//Подошло по цене

			//Компоненты подходят по минимальным требованиям
			if (gpt >= gpb && ppt >= ppb && rpt >= rpb) Sborki.push_back(sb);
			else if (gp <= gpb && pp <= ppb && rpt >= rpb) return Sborki;

			//Сбоираем следующую сборку пониже
			if (op > 0) op -= 10;
			if (gp > gpb) gp -= 10;
			if (pp > ppb) pp -= 10;
			//
			if (rp > rpb)
			{
				if ((configtype == 1 || configtype == 2) && op < 40) rp /= 2;
				else if (configtype == 3 && op < 70 && rp > rpb) rp /= 2;
				else if (configtype == 4 && op < 80 && rp > rpb) rp /= 2;
			}
			//
			if (st == 2 && sp == 256) st -= 1;
			else if (st == 1 && sp > 256) sp /= 2;
			else if (st == 2 && sp > 256) sp /= 2;
			//
			//делаем значения текущими
			opt = op;
		    gpt = gp;
			ppt = pp;
			rpt = rp;
			spt = sp;
			stt = st;
		}
		else //Занижаем временные критерии случайного компонента для попытки сбора более дешевой сборки
		{

			if (gpt > gpb && ppt > ppb && rpt > rpb )
			{
				srand(time(NULL));
				//Удешевляем какой-нибудь компонент
				int r = rand() % 4;

				while (true)
				{
					if (r == 0 && gpt > gpb)
					{
						gpt -= 10;
						break;
					}
					else r += 1;
					//
					if (r == 1 && ppt > ppb)
					{

						ppt -= 10;
						break;
					}
					else r += 1;
					//
					if (r == 2 && rpt > rpb)
					{
						rpt /= 2;
						break;
					}
					else r += 1;
					//
					if (r == 3)
					{
						if (stt == stb && spt == spb)
						{
							r = 0;
						}
						else if (stt == stb && spt > spb)
						{
							spt /= 2;
							break;
						}
						else if (stt > stb && spt == 256)
						{
							stt--;
							break;
						}
						else r = 0;
					}
					else r = 0;
				}
				i--;
			}
			else
			{
				//Сбоираем следующую сборку пониже
				if (op > 0) op -= 10;
				if (gp > 0) gp -= 10;
				if (pp > 0) pp -= 10;
				//
				if (rp > 4)
				{
					if ((configtype == 1 || configtype == 2) && op < 40) rp /= 2;
					else if (configtype == 3 && op < 70 && rp > rpb) rp /= 2;
					else if (configtype == 4 && op < 80 && rp > rpb) rp /= 2;
				}
				//
				if (st == 2 && sp == 256) st -= 1;
				else if (st == 1 && sp > 256) sp /= 2;
				else if (st == 2 && sp > 256) sp /= 2;
				//
				//делаем значения текущими
				opt = op;
				gpt = gp;
				ppt = pp;
				rpt = rp;
				spt = sp;
				stt = st;
			}

		}
	}

	return Sborki;
}