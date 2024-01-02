#pragma once
#include "figure.h"


class map_console
{
	bool map[30][22];
	bool mapVis[30][22];
	//bool status;

	figure fig;

	void initial();
	void update_MapVis();
	void update_MapDefault();

	bool checkLeft();
	bool checkRight();
	bool checkDown();
	//void checkLine();

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





