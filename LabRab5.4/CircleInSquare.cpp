#include "CircleInSquare.h"
#include <iostream>

CircleInSquare::CircleInSquare()
{
	Circle::fill_circle(0, 0, 0);
	Square::fill_square(0, 0, 0);
}

CircleInSquare::CircleInSquare(int x1, int y1, int R, int x2, int y2, int L)
{
	Circle::fill_circle(x1, y1, R);
	Square::fill_square(x2, y2, L);
}

void CircleInSquare::print_circleinsquare()
{
	Circle::print();
	std::cout << "\n";
	Square::print();
	int a;
	a = Square::x;
}

void CircleInSquare::check_circleinsquare()
{
	setlocale(LC_ALL, "Russian");
	if ((Square::x <= Circle::x - Circle::R) and (Square::y >= Circle::y + Circle::R) and (Square::y - Square::L <= Circle::y - Circle::R) and (Square::x + Square::L >= Circle::x + Circle::R)) {
		std::cout << "\n���������� � ��������\n";
	}
	else {
		std::cout << "\n���������� �� � ��������\n";
	}
}

void CircleInSquare::fill_circleinsquare()
{
	setlocale(LC_ALL, "Russian");
	int temp_x, temp_y, temp_R_or_L;
	std::cout << "��������� ������������ �����:\n";
	std::cout << "������� ���������� x >>> ";
	std::cin >> temp_x;
	std::cout << "������� ���������� y >>> ";
	std::cin >> temp_y;
	std::cout << "������� ������ ����� >>> ";
	std::cin >> temp_R_or_L;
	std::cout << "\n";
	Circle::fill_circle(temp_x, temp_y, temp_R_or_L);
	std::cout << "��������� ������������ ��������:\n";
	std::cout << "������� ���������� x >>> ";
	std::cin >> temp_x;
	std::cout << "������� ���������� y >>> ";
	std::cin >> temp_y;
	std::cout << "������� ����� ������� >>> ";
	std::cin >> temp_R_or_L;
	Square::fill_square(temp_x, temp_y, temp_R_or_L);

}
