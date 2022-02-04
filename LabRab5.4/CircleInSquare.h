#pragma once
#include "Circle.h"
#include "Square.h"

class CircleInSquare: public Circle, Square
{
public:
	CircleInSquare();
	CircleInSquare(int x1, int y1, int R, int x2, int y2, int L);
	void fill_circleinsquare();
	void print_circleinsquare();
	void check_circleinsquare();
};
