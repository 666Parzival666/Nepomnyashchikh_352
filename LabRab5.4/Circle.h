#pragma once
#include "Position.h"

class Circle: virtual public Position
{
public:
	int R;
	Circle();
	Circle(int temp_x, int temp_y, int temp_R);
	void fill_circle();
	void fill_circle(int temp_x, int temp_y, int temp_R);
	void perimetr_circle();
	void area_circle();
	void print();  // вывод информации о круге
};

