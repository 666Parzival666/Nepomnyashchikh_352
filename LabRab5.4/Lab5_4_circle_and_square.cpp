#include <iostream>
#include "Circle.h"
#include "Square.h"
#include "CircleInSquare.h"

int main()
{
    /*Circle temp_circle(1, 0, 5);
    temp_circle.print();
    /*Square temp_square(15, 50, 8);
    temp_square.print();*/

    Circle temp_circle;
    std::cout << "\n";
    temp_circle.fill_circle();
    std::cout << "\n";
    temp_circle.print();
    std::cout << "\n";
    temp_circle.perimetr_circle();
    std::cout << "\n";
    temp_circle.area_circle();

    Square temp_square;
    std::cout << "\n";
    temp_square.fill_square();
    std::cout << "\n";
    temp_square.print();
    std::cout << "\n";
    temp_square.perimetr_square();
    std::cout << "\n";
    temp_square.area_square();

    CircleInSquare temp_circle_in_square(1,2,3,1,2,6);
    std::cout << "\n";
    //temp_circle_in_square.fill_circleinsquare();
    std::cout << "\n";
    temp_circle_in_square.print_circleinsquare();
    std::cout << "\n";
    temp_circle_in_square.area_circle();
    std::cout << "\n";
    temp_circle_in_square.check_circleinsquare();
    
}