#pragma once
#include <vector>
#include <sstream>




struct Figure2d {
	unsigned int col, line;
	bool fig[3][2];
};

class figure
{
	Figure2d point;

	bool checkLeft();
	bool checkRight();

public:

	figure()
	{
		initialFig();
	}

	void initialFig();

	void moveLeft();
	void moveRight();
	void moveDown();

	Figure2d get_point();
};

