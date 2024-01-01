#pragma once
#include "figure.h"


class map_console
{
	bool map[29][20];
	bool mapVis[29][20];
	//bool status;

	figure fig;

	void initial();
	void update_MapVis();

	bool checkLeft();
	bool checkRight();
	bool checkDown();

public:

	map_console()
	{
		initial();
		update_MapVis();
		visual();
	}

	void visual();
	void update();
	void movefig();

	void check_conflict();
};





