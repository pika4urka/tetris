#include <iostream>
#include <random>
#include <cstdlib>
#include "map_console.h"
#include <conio.h>
#include "figure.h"


using namespace std;


int main()
{
	/*int code;
	code = _getch();
	cout << code << endl;

	while (code != 13)
	{
		code = _getch();
		cout << code << endl;
	}*/


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
		cerr << err.what();
		exit(0);
	}
}

