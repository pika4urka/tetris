#include <iostream>
#include "map_console.h"
#include "figure.h"
#include <Windows.h>

using namespace std;


int main()
{
	system("color 07");
	cout << "Controll: ASD\nTurn: QE\n";
	cout << endl << "click any button to continue\n";
	system("pause");
	
	map_console map;
	try 
	{
		while(true)
		{
			map.update();
		}
	}
	catch(exception& err)
	{
		map_console::SetColor(4, 0);
		cerr << endl << err.what();
		map_console::SetColor(7, 0);
	}

	return 0;
}

