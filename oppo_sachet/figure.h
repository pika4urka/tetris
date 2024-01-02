#pragma once
#include <vector>
#include <sstream>


struct Figure2d {
	unsigned int col, line;
	bool** fig;
	int status;

	bool** fig1;
	bool** fig2;
	bool** fig3;
	bool** fig4;
};

class figure
{
	Figure2d point;
	
	void initialMatrix();
	void deleteMatrix();
	void updStatusForFig(int num);
	void createFig4(const std::stringstream& ist);

public:

	figure()
	{
		initialMatrix();
		createFig();
	}

	~figure()
	{
		deleteMatrix();
	}

	void createFig();
	void moveLeft();
	void moveRight();
	void moveDown();
	void turn_left();
	void turn_right();

	Figure2d get_point();
};

