#include "figure.h"
#include <random>

const std::stringstream fig1("0100010001100000 0000111010000000 0110001000100000 0010111000000000"); //!
const std::stringstream fig2("1000110001000000 0110110000000000 1000110001000000 0110110000000000");
const std::stringstream fig3("0100110010000000 1100011000000000 0100110010000000 1100011000000000");
const std::stringstream fig4("0010001001100000 1000111000000000 0110010001000000 0000111000100000"); //!
const std::stringstream fig5("1100110000000000 1100110000000000 1100110000000000 1100110000000000");
const std::stringstream fig6("0100010001000100 0000111100000000 0100010001000100 0000111100000000");
const std::stringstream fig7("0100110001000000 0100111000000000 0100011001000000 0000111001000000");


void figure::initialMatrix()
{
	point.fig1 = new bool* [4];
	point.fig2 = new bool* [4];
	point.fig3 = new bool* [4];
	point.fig4 = new bool* [4];

	for (int i = 0; i < 4; i++)
	{
		point.fig1[i] = new bool[4];
		point.fig2[i] = new bool[4];
		point.fig3[i] = new bool[4];
		point.fig4[i] = new bool[4];
	}
}

void figure::deleteMatrix()
{
	for (int i = 0; i < 4; i++)
	{
		delete[] point.fig1[i];
		delete[] point.fig2[i];
		delete[] point.fig3[i];
		delete[] point.fig4[i];
	}

	delete[] point.fig1;
	delete[] point.fig2;
	delete[] point.fig3;
	delete[] point.fig4;
}

void figure::updStatusForFig(int num)
{
	switch (num)
	{
	case 1:
		point.fig = point.fig1;
		break;

	case 2:
		point.fig = point.fig2;
		break;

	case 3:
		point.fig = point.fig3;
		break;

	case 4:
		point.fig = point.fig4;
		break;
	}
}

void figure::turn_left()
{
	point.status = (point.status == 1) ? 4 : point.status - 1;
	updStatusForFig(point.status);
}

void figure::turn_right()
{
	point.status = (point.status == 4) ? 1 : point.status + 1;
	updStatusForFig(point.status);
}

//std::vector<std::istringstream> figure::splitting_the_stream(const std::stringstream& ist)
//{
//	std::vector<std::istringstream> vec;
//	std::istringstream buf(ist.str());
//	char str1[16], str2[16], str3[16], str4[16];
//
//	buf.getline(str1, 16);
//	buf.getline(str2, 16);
//	buf.getline(str3, 16);
//	buf.getline(str4, 16);
//
//	std::istringstream buf1(str1);
//	std::istringstream buf2(str2);
//	std::istringstream buf3(str3);
//	std::istringstream buf4(str4);
//
//	vec.push_back(buf1);
//	vec.push_back(buf2);
//	vec.push_back(buf3);
//	vec.push_back(buf4);
//}

void figure::createFig4(const std::stringstream& ist)
{
	std::istringstream buf(ist.str());
	std::string str1, str2, str3, str4;

	buf >> str1 >> str2 >> str3 >> str4;

	std::istringstream buf1(str1);
	std::istringstream buf2(str2);
	std::istringstream buf3(str3);
	std::istringstream buf4(str4);

	bool** arr1, ** arr2, ** arr3, ** arr4;
	int num;

	arr1 = point.fig1;
	arr2 = point.fig2;
	arr3 = point.fig3;
	arr4 = point.fig4;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			num = (buf1.get() == 49) ? 1 : 0;
			*(*(arr1 + i) + j) = num;
			num = (buf2.get() == 49) ? 1 : 0;
			*(*(arr2 + i) + j) = num;
			num = (buf3.get() == 49) ? 1 : 0;
			*(*(arr3 + i) + j) = num;
			num = (buf4.get() == 49) ? 1 : 0;
			*(*(arr4 + i) + j) = num;
		}

	point.fig = arr1;
}

void figure::createFig()
{
	int index = 0;
	index = rand() % 7;

	switch (index)
	{
	case 1:
		createFig4(fig1);
		break;

	case 2:
		createFig4(fig2);
		break;

	case 3:
		createFig4(fig3);
		break;

	case 4:
		createFig4(fig4);
		break;

	case 5:
		createFig4(fig5);
		break;

	case 6:
		createFig4(fig6);
		break;

	case 0:
		createFig4(fig7);
		break;
	}

	point.col = 9;
	point.line = 1;
	point.status = 1;
}

void figure::moveLeft()
{
	point.col -= 1;
}

void figure::moveRight()
{
	point.col += 1;
}

void figure::moveDown()
{
	point.line += 1;
}

Figure2d figure::get_point()
{
	return point;
}

