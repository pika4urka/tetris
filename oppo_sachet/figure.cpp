#include "figure.h"
#include <random>

const std::stringstream fig1("101011");
const std::stringstream fig2("101101");
const std::stringstream fig3("011110");
const std::stringstream fig4("111100");
const std::stringstream fig5("010111");

void figure::initialFig()
{
	int index = 0;
	std::string str;
	index = rand() % 4;

	switch (index)
	{
	case 1:
		str = fig1.str();
		break;

	case 2:
		str = fig2.str();
		break;

	case 3:
		str = fig3.str();
		break;

	case 4:
		str = fig4.str();

	case 0:
		str = fig5.str();
		break;
	}

	point.col = 9;
	point.line = 0;
	int num;
	std::istringstream buf(str);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
		{
			num = (buf.get() == 49) ? 1 : 0;
			point.fig[i][j] = num;
		}
}


bool figure::checkLeft()
{
	return (point.col != 0) ? true : false;
}

bool figure::checkRight()
{
	return (point.col != 18) ? true : false;
}

void figure::moveLeft()
{
	//if (checkLeft())
		point.col -= 1;
	//if (point.line == 26)
	//	throw::std::exception("end");
}

void figure::moveRight()
{
	//if (checkRight())
		point.col += 1;
	//if (point.line == 26)
	//	throw::std::exception("end");
}

void figure::moveDown()
{
	point.line += 1;
	//if (point.line == 26)
	//	throw::std::exception("end");
}

Figure2d figure::get_point()
{
	return point;
}

