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
	srand(time(NULL));

	//Генерация сборок

	//максимальные очки производительности каждого комплектующего от критерия
	int MaxGraphicPoints = 40;
	int MaxProcPoints = 40;
	int MaxRAMPoints = 8;  //Критерии для домашней сборки
	int MaxSATAPoints = 512;
	int MaxSATAType = 1;

	if (configtype == 2) //Критерии для офисного компьютера
	{
		MaxGraphicPoints = 40;  MaxProcPoints = 60;
		MaxRAMPoints = 8;
		MaxSATAPoints = 512; MaxSATAType = 1;
	}
	else if (configtype == 3) //Критерии для игрового компьютера
	{
		MaxGraphicPoints = 80; MaxProcPoints = 70;
		MaxRAMPoints = 16;
		MaxSATAPoints = 256; MaxSATAType = 2;
	}
	else  if (configtype == 4) //Критерии для профессионального компьютера
	{
		MaxGraphicPoints = 1000; MaxProcPoints = 1000;
		MaxRAMPoints = 64;
		MaxSATAPoints = 1024; MaxSATAType = 2;
	}

	//Минимальные границы очков производительности, дальше которых не будут подибраться сборки

	int MinGraphicPoints = 0;
	int MinProcPoints = 0;
	int MinRAMPoints = 4;
	int MinSATAPoints = 256;
	int MinSATAType = 1;

	if (configtype == 2)
	{
		MinGraphicPoints = 10; MinProcPoints = 20;
	}
	else if (configtype == 3)
	{
		MinGraphicPoints = 30; MinProcPoints = 30;
		MinRAMPoints = 8;
		MinSATAPoints = 512;
	}
	else if (configtype == 4)
	{
		MinGraphicPoints = 40; MinProcPoints = 50;
		MinRAMPoints = 8;
		MinSATAPoints = 512; MinSATAType = 1;
	}

	//Процессоры, подходящие к видеокарте
	std::vector<Processor> ProcRange;

	//Поиск видеокарт, подходящих по критериям
	for (int i = cards.size() - 1; i >= 0; i--)
		if (cards[i].GetPoints() > MaxGraphicPoints) cards.erase(cards.begin() + i);
		else if (cards[i].GetPoints() < MinGraphicPoints) cards.erase(cards.begin() + i);

	//Поиск процессоров, подходящих по критериям
	for (int i = process.size() - 1; i >= 0; i--)
		if (process[i].GetPoints() > MaxProcPoints) process.erase(process.begin() + i);
		else if (process[i].GetPoints() < MinProcPoints) process.erase(process.begin() + i);

	//Для временного хранения выборов комплектации
	GraphicsCard card;
	Processor proces;
	Motherboard mother;
	RAM ram;
	SATA sata;
	PowerBlock power;

	//Собранные сборки
	std::vector<Sborka> Sborki;

	//Текущие данные для циклов сборки
	int CurrentRAMPoints = MaxRAMPoints;
	int CurrentSATAPoints = MaxSATAPoints;
	int CurrentSATAType = MaxSATAType;
	int tdp = 0;

	//Первая по мощности видеокарта
	int GraphicNumber = cards.size() - 1;
	card = cards[GraphicNumber];

	// Поиск процессоров, подходящих к текущей видеокарте
	if (ProcRange.empty())
		for (int j = 0; j < process.size(); j++) if (abs(process[j].GetPoints() - card.GetPoints()) <= 20) ProcRange.push_back(process[j]); 

	//Генерация сборок
	while (true)
	{
		tdp = 0;
		//Запись видеокарты и её энергопотребления
		card = cards[GraphicNumber];
		tdp += card.GetTdp();

		//Запись процессора и его энергопотребления
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

			if (rams[c].GetGB() < (int)CurrentRAMPoints) b = c + 1;
			else e = c;
		}

		if (b > (rams.size() - 1)) b = rams.size() - 1;
		ram = rams[b];

		//Поиск жесткого диска по мощности
		b = 0;
		e = sats.size();
		for (int j = 0; j < e; j++)
			if (sats[j].GetGB() == CurrentSATAPoints && sats[j].GetType() == CurrentSATAType)
			{
				b = j;
				break;
			}

		sata = sats[b];

		//Поиск блока питания по энергопотреблению
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

		
		if (sb.GetCost() >= mincost && sb.GetCost() <= maxcost)
		{
		//Сохраняем сборку, если она подходит по цене и собираем следующую сборку 
			Sborki.push_back(sb);

			//Переходим к следующему процессору, который подходит к выбранной видеокарте, если таковых нет, то меняем видеокарту
			if (ProcRange.size() > 1) ProcRange.erase(ProcRange.begin() + ProcRange.size() - 1); //Следующий процессор
			else
			{
				//Следующая видеокарта
				cards.erase(cards.begin() + cards.size() - 1);
				GraphicNumber = cards.size() - 1;
				
				//Если кончились видеокарты, подходящие по критериям
				if (cards.empty()) return Sborki;
				else
				{
					card = cards[GraphicNumber];
					ProcRange.clear();
					for (int j = 0; j < process.size(); j++) if (abs(process[j].GetPoints() - card.GetPoints()) <= 20) ProcRange.push_back(process[j]);
				}
			}

			//Сброс критериев вторичных компонентов
			CurrentSATAType = MaxSATAType;
			CurrentSATAPoints = MaxSATAPoints;
			CurrentRAMPoints = MaxRAMPoints;
		}
		else //Не подошло по цене, уменьшаем не сильно значимые комплекутющие
		{
			if (CurrentSATAType != MinSATAType || CurrentSATAPoints != MinSATAPoints) //Жесткий диск
			{
				if (CurrentSATAType == MinSATAType && CurrentSATAPoints > MinSATAPoints)
				{
					CurrentSATAPoints /= 2;
					continue;
				}
				else if (CurrentSATAType > MinSATAType && CurrentSATAPoints == MinSATAPoints)
				{
					CurrentSATAType--;
					CurrentSATAPoints = 1024;
					continue;
				}
				else if (CurrentSATAType > MinSATAType && CurrentSATAPoints > MinSATAPoints)
				{
					CurrentSATAPoints /= 2;
					continue;
				}
				else if (CurrentSATAType > MinSATAType && CurrentSATAPoints == 256 && CurrentSATAPoints != MinSATAPoints)
				{
					CurrentSATAType--;
					CurrentSATAPoints = 1024;
					continue;
				}
			}
			else if (CurrentRAMPoints > MinRAMPoints)//Опреативная память
			{
				CurrentRAMPoints /= 2;
				continue;
			}
			else
			{
				if (ProcRange.size() > 1) //Переходим к следующему процессору, который подходит к выбранной видеокарте, если таковых нет, то меняем видеокарту
				{
					ProcRange.erase(ProcRange.begin() + ProcRange.size() - 1);
					//Сброс критериев вторичных компонентов
					CurrentSATAType = MaxSATAType;
					CurrentSATAPoints = MaxSATAPoints;
					CurrentRAMPoints = MaxRAMPoints;
					continue;
				}
				else //Уменьшаме мощность видеокарты
				{
					cards.erase(cards.begin() + cards.size() - 1);
					GraphicNumber = cards.size() - 1;
					//Если кончились видеокарты, подходящие по критериям
					if (cards.empty()) return Sborki;
					else
					{
						card = cards[GraphicNumber];
						ProcRange.clear();
						for (int j = 0; j < process.size(); j++) if (abs(process[j].GetPoints() - card.GetPoints()) <= 20) ProcRange.push_back(process[j]);
					}
					//Сброс критериев вторичных компонентов
					CurrentSATAType = MaxSATAType;
					CurrentSATAPoints = MaxSATAPoints;
					CurrentRAMPoints = MaxRAMPoints;

					continue;
				}
			}
		}
	}
}