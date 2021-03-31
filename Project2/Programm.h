#pragma once

#include <iostream>

class Programm
{
	std::string _progname;
	int _gp;
	int _pp;
	int _rp;
	int _sp;
	int _st;

	bool _linux;
	bool _win7;
	bool _win8;
	bool _win10;

public:

	void SetData(std::string progname, int gp, int pp, int rp, int sp, int st, bool linux, bool win7, bool win8, bool win10);

	std::string GetName();

	int GetGP();

	int GetPP();

	int GetRP();

	int GetSP();

	int GetST();

	bool GetLinux();

	bool GetWin7();

	bool GetWin8();

	bool GetWin10();
};

