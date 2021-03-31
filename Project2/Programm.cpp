#include "Programm.h"

void Programm::SetData(std::string progname, int gp, int pp, int rp, int sp, int st, bool linux, bool win7, bool win8, bool win10)
{
	_progname = progname;

	_gp = gp;
	_pp = pp;
	_rp = rp;
	_sp = sp;
	_st = st;

	_linux = linux;
	_win7 = win7;
	_win8 = win8;
	_win10 = win10;
}

int Programm::GetGP()
{
	return _gp;
}

int Programm::GetPP()
{
	return _pp;
}

int Programm::GetRP()
{
	return _rp;
}

std::string Programm::GetName()
{
	return _progname;
}

int Programm::GetSP()
{
	return _sp;
}

int Programm::GetST()
{
	return _st;
}

bool Programm::GetLinux()
{
	return _linux;
}

bool Programm::GetWin7()
{
	return _win7;
}

bool Programm::GetWin8()
{
	return _win8;
}

bool Programm::GetWin10()
{
	return _win10;
}
