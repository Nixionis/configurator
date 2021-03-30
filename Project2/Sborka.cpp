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

std::string Sborka::GetName() {

	return sborkaname;
}

void Sborka::SetName(std::string name) {
	sborkaname = name;
}
void Sborka::SetName(System::String^ name) {
	sborkaname = msclr::interop::marshal_as<std::string>(name);
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

bool Sborka::operator==(Sborka DifSborka)
{
	if (_card.GetPoints() == DifSborka.GetCard().GetPoints() && _mother.GetSocket() == DifSborka.GetMother().GetSocket()
		&& _prots.GetPoints() == DifSborka.GetProts().GetPoints() && _ram.GetGB() == DifSborka.GetRam().GetGB()
		&& _sata.GetGB() == DifSborka.GetSata().GetGB() && _sata.GetType() == DifSborka.GetSata().GetType()
		&& _power.GetWatt() == DifSborka.GetPower().GetWatt()) return true;

	return false;
}

bool Sborka::operator<(Sborka DifSborka)
{
	return (_cost < DifSborka.GetCost());
}
