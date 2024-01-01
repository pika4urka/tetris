#include <iostream>
#include "map_console.h"
#include <cstdlib>
#include <conio.h>
#include <Windows.h>


void SetColor(int text, int bg) 
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}


void map_console::initial()
{
	for (int i = 0; i < 29; i++)
		for (int j = 0; j < 20; j++)
		{
			map[i][j] = 0;
			mapVis[i][j] = 0;
		}
}


void map_console::visual()
{
	system("cls");

	for (int i = 0; i < 29; i++)
	{
		//std::cout << "\t\t\t\t\t\t";
		for (int j = 0; j < 20; j++)
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

	/*int code = _getch();

	switch (code)
	{
	case 97:
		fig.moveLeft();
	}*/

	int code = _getch();
	try
	{
		switch (code)
		{
		case 97:
			fig.moveLeft();
			break;

		case 100:
			fig.moveRight();
			break;

		default:
			fig.moveDown();
			break;
		}
	}
	catch (std::exception& err)
	{
		update_MapVis();
		visual();
		SetColor(7, 0);
		throw::std::exception(err.what());

		// ...#################################################create new def map
	}
	
	//...######################################################create next fig
}


void map_console::update_MapVis()
{
	for (int i = 0; i < 29; i++)
		for (int j = 0; j < 20; j++)
			mapVis[i][j] = map[i][j];

	{
		auto point = fig.get_point();
		int col = point.col, line = point.line;
		//coord for figure
		{
			mapVis[line][col] = 1;
			mapVis[line + 1][col] = 1;
			mapVis[line + 2][col] = 1;
			mapVis[line + 2][col + 1] = 1;
		}
	}
}


//void map_console::check_conflict()
//{
//	auto vec = fig.get_point();
//
//	if (map[vec.at()][vec.at()])
//}