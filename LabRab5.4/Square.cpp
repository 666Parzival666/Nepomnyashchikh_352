#include "Square.h"
#include <iostream>
Square::Square()
{
	this->x = 0;
	this->y = 0;
	this->L = 0;
}

Square::Square(int temp_x, int temp_y, int temp_L) :Position(temp_x, temp_y)
{
	this->L = temp_L;
}

void Square::fill_square()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Настройка конфигурации квадрата:\n";
	std::cout << "Введите координату x >>> ";
	std::cin >> this->x;
	std::cout << "Введите координату y >>> ";
	std::cin >> this->y;
	std::cout << "Введите длину стороны >>> ";
	std::cin >> this->L;
}

void Square::fill_square(int temp_x, int temp_y, int temp_L)
{
	this->x = temp_x;
	this->y = temp_y;
	this->L = temp_L;
}

void Square::perimetr_square()
{
	std::cout << "Периметр квадрата >>> " << this->L * 4;
}

void Square::area_square()
{
	std::cout << "Площадь квадрата >>> " << this->L * this->L;
}

void Square::print()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Конфигурация квадрата\n";
	std::cout << "x = " << this->x << "\n"
		<< "y = " << this->y << "\n"
		<< "Длина стороны = " << this->L << "\n";
}
