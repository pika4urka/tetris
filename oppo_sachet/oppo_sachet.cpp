#include <iostream>
#include <random>
#include <cstdlib>
#include "map_console.h"
#include <conio.h>


using namespace std;


void map_console::update()
{
	movefig();
	update_MapVis();
	visual();

}



int main()
{
	//system("color 03");
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
		//system("color 07");
		cerr << err.what();
		exit(0);
	}
}

