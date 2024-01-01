#include "figure.h"


void figure::initialFig()
{
	point.col = 9;
	point.line = 0;
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
	if (checkLeft())
		point.col -= 1;
	if (point.line == 26)
		throw::std::exception("end");
}

void figure::moveRight()
{
	if (checkRight())
		point.col += 1;
	if (point.line == 26)
		throw::std::exception("end");
}

void figure::moveDown()
{
	point.line += 1;
	if (point.line == 26)
		throw::std::exception("end");
}

Figure2d figure::get_point()
{
	return point;
}

