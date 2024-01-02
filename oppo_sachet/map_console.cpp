#include <iostream>
#include "map_console.h"
#include <cstdlib>
#include <conio.h>
#include <Windows.h>


bool map_console::checkTurn()
{
	bool flag = false;
	auto point = fig.get_point();
	bool** matrix = point.fig;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if ((*(*(matrix + i) + j)) && (map[i + point.line][j + point.col]))
			{
				flag = true;
				break;
			}
		if (flag) break;
	}
	return flag;
}

void map_console::update()
{
	movefig();
	update_MapVis();
	visual();
}

void map_console::SetColor(int text, int bg)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void map_console::initial()
{
	for (int i = 0; i < 35; i++)
		for (int j = 0; j < 25; j++)
		{
			if (i == 32)
			{
				map[i][j] = 1;
				mapVis[i][j] = 1;
			}
			else 
			if ((j == 1) || (j == 22))
			{
				map[i][j] = 1;
				mapVis[i][j] = 1;
			}
			else
			{
				map[i][j] = 0;
				mapVis[i][j] = 0;
			}
		}
}

bool map_console::checkLeft()
{
	auto point = fig.get_point();
	int col = point.col;
	int line = point.line;
	bool flag = true;
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if ((*(*(point.fig + i) + j) == true) && (map[line + i][col + j - 1] == true))
				flag = false;
	return flag;
}

bool map_console::checkRight()
{
	auto point = fig.get_point();
	int col = point.col;
	int line = point.line;
	bool flag = true;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if ((*(*(point.fig + i) + j) == true) && (map[line + i][col + j + 1] == true))
				flag = false;
	return flag;
}

bool map_console::checkDown()
{
	auto point = fig.get_point();
	int col = point.col;
	int line = point.line;
	bool flag = true;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if ((*(*(point.fig + i) + j) == true) && (map[line + i + 1][col + j] == true))
				throw::std::exception("end");
	return flag;
}

void map_console::visual()
{
	system("cls");

	for (int i = 3; i < 32; i++)
	{
		for (int j = 2; j < 22; j++)
		{
			if (mapVis[i][j] == 0)
				SetColor(14, 0);
			else
				SetColor(9, 0);
			std::cout << mapVis[i][j];
		}
		std::cout << std::endl;
	}
	SetColor(6, 0);
	std::cout << "POINTS: ";
	SetColor(11, 0);
	std::cout << points;
}

void map_console::movefig()
{
	int code = _getch();
	try
	{
		switch (code)
		{
		case 32:
			exit(0);

		case 169:
		case 113:
			fig.turn_left();
			if (checkTurn())
				fig.turn_right();
			break;

		case 227:
		case 101:
			fig.turn_right();
			if (checkTurn())
				fig.turn_left();
			break;

		case 228:
		case 97:
			if (checkLeft())
				fig.moveLeft();
			break;

		case 162:
		case 100:
			if (checkRight())
				fig.moveRight();
			break;

		default:
			if (checkDown())
				fig.moveDown();
			break;
		}
	}
	catch (std::exception& err)
	{

		int line;
		auto point = fig.get_point();

		if (point.line <= 3)
			throw::std::exception("GAME OVER!");
		
		try
		{
			while (true)
			{
				line = checkLine(point.line);
				matrixOffset(line);
				points++;
			}
		}
		catch (std::exception& err) {};

		update_MapDefault();
		fig.createFig();
		update_MapVis();
		visual();
	}
}

void map_console::update_MapVis()
{
	for (int i = 0; i < 32; i++)
		for (int j = 2; j < 22; j++)
			mapVis[i][j] = map[i][j];

	auto point = fig.get_point();
	int col = point.col, line = point.line;
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				mapVis[line + i][col + j] = mapVis[line + i][col + j] or *(*(point.fig + i) + j);
	}

}

void map_console::update_MapDefault()
{
	for (int i = 0; i < 32; i++)
		for (int j = 2; j < 22; j++)
			map[i][j] = mapVis[i][j];
}

int map_console::checkLine(int line)
{
	bool flag;
	for (int i = line; i < 32; i++)
	{
		flag = true;
		for (int j = 2; j < 22; j++)
			if (mapVis[i][j] == 0)
			{
				flag = false;
				break;
			}
		if (flag)
			return i;
	}
	throw::std::exception("no_delete");
}

void map_console::matrixOffset(int line)
{
	for (int i = line; i > 1; i--)
		for (int j = 2; j < 22; j++)
		{
			mapVis[i][j] = mapVis[i - 1][j];
		}
}