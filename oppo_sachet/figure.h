#pragma once
#include <vector>

struct Figure2d {
	unsigned int col, line;
	bool fig[3][2];
};

class figure
{
	Figure2d point;

	//bool figVis[3][2];

	bool checkLeft();
	bool checkRight();

public:

	figure()
	{
		initialFig();
		/*point.push_back(0);
		point.push_back(9);*/
	}
	
	//figure()
	//{
	//	for (int i = 0; i < 3; i++)
	//		*(figVis + i) = new bool[2];
	//	//initial
	//	{
	//		*(*(figVis + 0) + 0) = 1; *(*(figVis + 0) + 1) = 0;
	//		*(*(figVis + 1) + 0) = 1; *(*(figVis + 1) + 1) = 0;
	//		*(*(figVis + 2) + 0) = 1; *(*(figVis + 2) + 1) = 1;
	//	}	
	//}

	/*~figure()
	{
		for (int i = 0; i < 3; i++)
			delete[](figVis + i);
		delete[] figVis;
	}*/

	void initialFig();
	//void destructFig();
	void moveLeft();
	void moveRight();
	void moveDown();

	Figure2d get_point();
};

