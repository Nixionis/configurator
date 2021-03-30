#pragma once

#include <ctime>
#include <vector>
#include <fstream>

#include "Sborka.h"

std::vector<GraphicsCard> LoadGraphicsData()
{
	//Загрузка в базу данных графических карт
	std::vector<GraphicsCard> cards;
	GraphicsCard card;
	 
	//Открытие файла
	std::fstream GraphicFile("Graphics.txt");

	//Данные, считанные с одной строки
	int amount;
	std::string name;
	int power;
	int cost;
	int tdp;

	GraphicFile >> amount;
	//Считывание всего списка видеокарт
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

	//Открытие файла
	std::fstream MBoardFile("Mboards.txt");

	//Данные, считанные с одной строки
	int amount;
	std::string name;
	int powermin;
	int powermax;
	int cost;
	int size;
	int socket;

	MBoardFile >> amount;
	//Считывание всего списка материнских плат
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

	//Открытие файла
	std::fstream ProccsFile("Proccs.txt");

	//Данные, считанные с одной строки
	int amount;
	std::string name;
	int power;
	int cost;
	int socket;
	int tdp;

	ProccsFile >> amount;
	//Считывание всего списка процессоров
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

	//Открытие файла
	std::fstream RAMFile("RAM.txt");

	//Данные, считанные с одной строки
	int amount;
	std::string name;
	int GBs;
	int cost;

	RAMFile >> amount;
	//Считывание всего списка оперативной памяти
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

	//Открытие файла
	std::fstream SATAFile("SATA.txt");

	//Данные, считанные с одной строки
	int amount;
	std::string name;
	int GBs;
	int type;
	int cost;

	SATAFile >> amount;
	//Считывание всего списка жестких дисков
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

	//Открытие файла
	std::fstream PowerFile("PowerBlocks.txt");

	//Данные, считанные с одной строки
	int amount;
	std::string name;
	int Watt;
	int cost;

	PowerFile >> amount;
	//Считывание всего списка блоков питания
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

std::vector<Sborka> CreateConfigas(int configtype, int mincost, int maxcost, std::vector<GraphicsCard> cards,
	std::vector<Motherboard>& mothers, std::vector<Processor> process, std::vector<RAM>& rams, std::vector<SATA>& sats, std::vector<PowerBlock>& powers)
{
	//Генерация сборок
	//Сид рандома

	srand(time(NULL));

	int k = 0;
	//Очки мощности от типа
	int gp = 40;
	int pp = 40;
	int rp = 8;
	int sp = 512;
	int st = 1;

	if (configtype == 2)
	{
		gp = 40;  pp = 60;
		rp = 8;
		sp = 512; st = 1;
	}
	else if (configtype == 3)
	{
		gp = 80; pp = 70;
		rp = 16;
		sp = 256; st = 2;
	}
	else  if (configtype == 4)
	{
		gp = 1000; pp = 1000;
		rp = 64;
		sp = 1024; st = 2;
	}

	//Минимальные границы до куда подбирать сборки

	int gpb = 0;
	int ppb = 0;
	int rpb = 4;
	int spb = 256;
	int stb = 1;

	if (configtype == 2)
	{
		gpb = 10; ppb = 20;
	}
	else if (configtype == 3)
	{
		gpb = 30; ppb = 30;
		rpb = 8;
		spb = 512;
	}
	else if (configtype == 4)
	{
		gpb = 40; ppb = 50;
		rpb = 8;
		spb = 512; stb = 1;
	}

	std::vector<GraphicsCard> CardRange;
	std::vector<Processor> ProcRange;
	//ProcRange = process;

	for (int i = cards.size() - 1; i >= 0; i--)
		if (cards[i].GetPoints() > gp) cards.erase(cards.begin() + i);
		else if (cards[i].GetPoints() < gpb) cards.erase(cards.begin() + i);

	for (int i = process.size() - 1; i >= 0; i--)
		if (process[i].GetPoints() > pp) process.erase(process.begin() + i);
		else if (process[i].GetPoints() < ppb) process.erase(process.begin() + i);

	//Для хранения временных выборов
	GraphicsCard card;
	Processor proces;
	Motherboard mother;
	RAM ram;
	SATA sata;
	PowerBlock power;

	//Собранные сборки
	std::vector<Sborka> Sborki;

	//Текущие данные для циклов сборки
	int rpt = rp;
	int spt = sp;
	int stt = st;
	int tdp = 0;

	int GraphicNumber = cards.size() - 1;

	card = cards[GraphicNumber];

	if (ProcRange.empty())
		for (int j = 0; j < process.size(); j++) if (abs(process[j].GetPoints() - card.GetPoints()) <= 20) ProcRange.push_back(process[j]); //Процессоры, подходящие к текущей видеокарте

		//Генерация (i) сборок

	while (true)
	{
		tdp = 0;
		//Запись видеокарты
		card = cards[GraphicNumber];
		tdp += card.GetTdp();

		//Запись процессора
		proces = ProcRange[ProcRange.size() - 1];
		tdp += proces.GetTdp() + 175;

		//Поиск материнской карты по сокету процессора

		int b = 0;
		int e = mothers.size();

		for (; mothers[b].GetSocket() != proces.GetSocket(); b++);

		mother = mothers[b];

		//Поиск оперативной памяти

		b = 0;
		e = rams.size();

		while (b < e)
		{
			int c = (b + e) / 2;

			if (rams[c].GetGB() < (int)rpt) b = c + 1;
			else e = c;
		}

		if (b > (rams.size() - 1)) b = rams.size() - 1;
		ram = rams[b];

		//Поиск жесткого диска по мощности

		b = 0;
		e = sats.size();
		for (int j = 0; j < e; j++)
			if (sats[j].GetGB() == spt && sats[j].GetType() == stt)
			{
				b = j;
				break;
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

		Sborka sb;
		sb.SetConfig(card, mother, proces, ram, sata, power);

		//Сохраняем сборку, если она подоходит по цене и собираем следующую сборку 
		if (sb.GetCost() >= mincost && sb.GetCost() <= maxcost)
		{
			Sborki.push_back(sb);

			if (ProcRange.size() > 1) ProcRange.erase(ProcRange.begin() + ProcRange.size() - 1);
			else
			{
				cards.erase(cards.begin() + cards.size() - 1);
				GraphicNumber = cards.size() - 1;

				if (cards.empty()) return Sborki;
				else
				{
					card = cards[GraphicNumber];
					ProcRange.clear();
					for (int j = 0; j < process.size(); j++) if (abs(process[j].GetPoints() - card.GetPoints()) <= 20) ProcRange.push_back(process[j]);
				}
			}

			stt = st;
			spt = sp;
			rpt = rp;
		}
		else //Не подошло по цене, уменьшаем не сильно значимые комплекутющие
		{
			if (stt != stb || spt != spb) //Жесткий диск
			{
				if (stt == stb && spt > spb)
				{
					spt /= 2;
					continue;
				}
				else if (stt > stb && spt == spb)
				{
					stt--;
					spt = 1024;
					continue;
				}
				else if (stt > stb && spt > spb)
				{
					spt /= 2;
					continue;
				}
				else if (stt > stb && spt == 256 && spt != spb)
				{
					stt--;
					spt = 1024;
					continue;
				}
			}
			else if (rpt > rpb)//Опреативная память
			{
				rpt /= 2;
				continue;
			}
			else
			{
				if (ProcRange.size() > 1) //Уменьшаем мощность процессора
				{
					ProcRange.erase(ProcRange.begin() + ProcRange.size() - 1);
					stt = st;
					spt = sp;
					rpt = rp;
					continue;
				}
				else //Уменьшаме мощность видеокарты
				{
					cards.erase(cards.begin() + cards.size() - 1);
					GraphicNumber = cards.size() - 1;

					if (cards.empty()) return Sborki;
					else
					{
						card = cards[GraphicNumber];
						ProcRange.clear();
						for (int j = 0; j < process.size(); j++) if (abs(process[j].GetPoints() - card.GetPoints()) <= 20) ProcRange.push_back(process[j]);
					}

					stt = st;
					spt = sp;
					rpt = rp;

					continue;
				}
			}
		}
	}
}