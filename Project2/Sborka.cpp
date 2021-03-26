#include "Sborka.h"

void Sborka::SetConfig(GraphicsCard card, Motherboard mother, Processor prots, RAM ram, SATA sata, PowerBlock power)
{
	_card = card;
	_mother = mother;
	_prots = prots;
	_ram = ram;
	_sata = sata;
	_power = power;

	_cost = 0;
	_cost += card.GetCost();
	_cost += mother.GetCost();
	_cost += prots.GetCost();
	_cost += ram.GetCost();
	_cost += sata.GetCost();
	_cost += power.GetCost();
}

GraphicsCard Sborka::GetCard()
{
	return _card;
}

Motherboard Sborka::GetMother()
{
	return _mother;
}

Processor Sborka::GetProts()
{
	return _prots;
}

RAM Sborka::GetRam()
{
	return _ram;
}

SATA Sborka::GetSata()
{
	return _sata;
}

PowerBlock Sborka::GetPower()
{
	return _power;
}

int Sborka::GetCost()
{
	return _cost;
}
