#pragma once
#include "Position.h"

class Square: virtual public Position
{
public:
	int L;
	Square();
	Square(int temp_x, int temp_y, int temp_L);
	void fill_square();
	void fill_square(int temp_x, int temp_y, int temp_R);
	void perimetr_square();
	void area_square();
	void print();  // вывод информации о квадрате
};
