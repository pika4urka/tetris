#pragma once
#include "figure.h"


class map_console
{
	int points;
	bool map[35][25];
	bool mapVis[35][25];

	figure fig;

	void initial();
	void update_MapVis();
	void update_MapDefault();
	void matrixOffset(int line);

	bool checkLeft();
	bool checkRight();
	bool checkDown();
	bool checkTurn();

	int checkLine(int line);

public:

	map_console()
	{
		points = 0;
		initial();
		update_MapVis();
		visual();
	}

	static void SetColor(int text, int bg);

	void visual();
	void update();
	void movefig();
};





