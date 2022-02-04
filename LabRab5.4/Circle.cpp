#include "Circle.h"
#include <iostream>
Circle::Circle()
{
	this->x = 0;
	this->y = 0;
	this->R = 0;
}

Circle::Circle(int temp_x, int temp_y, int temp_R):Position(temp_x, temp_y)
{
	this->R = temp_R;
}

void Circle::fill_circle()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Настройка конфигурации круга:\n";
	std::cout << "Введите координату x >>> ";
	std::cin >> this->x;
	std::cout << "Введите координату y >>> ";
	std::cin >> this->y;
	std::cout << "Введите радиус круга >>> ";
	std::cin >> this->R;
}

void Circle::fill_circle(int temp_x, int temp_y, int temp_R)
{
	this->x = temp_x;
	this->y = temp_y;
	this->R = temp_R;
}

void Circle::perimetr_circle()
{
	std::cout << "Периметр круга >>> " << this->R * 2 * 3.14;
}

void Circle::area_circle()
{
	std::cout << "Площадь круга >>> " << this->R * this->R * 3.14;
}

void Circle::print()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Конфигурация круга\n";
	std::cout << "x = " << this->x << "\n" 
			  << "y = " << this->y << "\n" 
			  << "Радиус круга = " << this->R << "\n";
}
