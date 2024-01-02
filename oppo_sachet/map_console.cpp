#include <iostream>
#include "map_console.h"
#include <cstdlib>
#include <conio.h>
#include <Windows.h>



void map_console::update()
{
	movefig();
	update_MapVis();
	visual();
}


void SetColor(int text, int bg)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}


void map_console::initial()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 22; j++)
		{
			if (i == 29)
			{
				map[i][j] = 1;
				mapVis[i][j] = 1;
			}
			else 
			if ((j == 0) || (j == 21))
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


//дублирование кода

bool map_console::checkLeft()
{
	auto point = fig.get_point();
	int col = point.col;
	int line = point.line;
	bool flag = true;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			if ((point.fig[i][j] == true) && (map[line + i][col + j - 1] == true))
				flag = false;
	return flag;
}


bool map_console::checkRight()
{
	auto point = fig.get_point();
	int col = point.col;
	int line = point.line;
	bool flag = true;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			if ((point.fig[i][j] == true) && (map[line + i][col + j + 1] == true))
				flag = false;
	return flag;
}


bool map_console::checkDown()
{
	auto point = fig.get_point();
	int col = point.col;
	int line = point.line;
	bool flag = true;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			if ((point.fig[i][j] == true) && (map[line + i + 1][col + j] == true))
				throw::std::exception("end");
	return flag;
}


void map_console::visual()
{
	system("cls");

	for (int i = 0; i < 29; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			if (mapVis[i][j] == 0)
				SetColor(14, 0);
			else
				SetColor(9, 0);
			std::cout << mapVis[i][j];
		}
		std::cout << std::endl;
	}
}


void map_console::movefig()
{


	int code = _getch();
	try
	{
		switch (code)
		{
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
		update_MapDefault();
		fig.initialFig();
		update_MapVis();
		visual();
	}
	
	//...######################################################create next fig
}


void map_console::update_MapVis()
{
	for (int i = 0; i < 29; i++)
		for (int j = 1; j < 21; j++)
			mapVis[i][j] = map[i][j];

	auto point = fig.get_point();
	int col = point.col, line = point.line;
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 2; j++)
				mapVis[line + i][col + j] = mapVis[line + i][col + j] or point.fig[i][j];
	}

}


void map_console::update_MapDefault()
{
	for (int i = 0; i < 29; i++)
		for (int j = 1; j < 21; j++)
			map[i][j] = mapVis[i][j];
}