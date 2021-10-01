// Lab1_DataTypes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <bitset>
#include <limits.h>


using std::cout;
using std::endl;
using std::cin;

int main() {
	setlocale(LC_ALL, "Russian"); //Русский язык

	// 1) ФИО, номер группы;
	cout << "№_1" << endl;
	cout << "Непомнящих Игорь 211-352" << "\n" << endl;

	//2) минимальные и максимальные значения встроенных типов данных, а так же их размер;
	cout << "№_2" << endl;
	cout << "min int = " << INT_MIN << ", " << "max int = " << INT_MAX << ", " << "size of int = " << sizeof(int) << endl;
	cout << "min unsigned int = 0" << ", " << "max unsigned int = " << UINT_MAX << ", " << "size of unsigned int = " << sizeof(unsigned int) << endl;
	cout << "min short = " << SHRT_MIN << ", " << "max short = " << SHRT_MAX << ", " << "size of short = " << sizeof(short) << endl;
	cout << "min unsigned short = 0" << ", " << "max unsigned short = " << USHRT_MAX << ", " << "size of unsigned short = " << sizeof(unsigned short) << endl;
	cout << "min long = " << LONG_MIN << ", " << "max long = " << LONG_MAX << ", " << "size of long = " << sizeof(long) << endl;
	cout << "min long long = " << LLONG_MIN << ", " << "max int = " << LLONG_MAX << ", " << "size of long long = " << sizeof(long long) << endl;
	cout << "min double = " << DBL_MIN << ", " << "max double = " << DBL_MAX << ", " << "size of double = " << sizeof(double) << endl;
	cout << "min char = " << CHAR_MIN << ", " << "max char = " << CHAR_MAX << ", " << "size of char = " << sizeof(char) << endl;
	cout << "min bool = False" << ", " << "max bool = True" << ", " << "size of bool = " << sizeof(bool) << endl;

	//3) запросить у пользователя некоторое целое число и вывести на экран это число в бинарном и шестнадцатиричном виде, а так же результат преобразования типов ко всем встроенным;
	cout << "№_3" << endl;
	int v;
	cout << "Введите число: "; cin >> v;
	cout << "В бинарном виде: " << std::bitset<16>(v) << endl;
	cout << "В шестнадцатиричном виде: " << std::hex << v << endl;
	if (v < 0) {
		cout << "Bool: 0" << endl;
	}
	else {
		cout << "Bool: 1" << endl;
	}
	cout << "Double: " << double(v) << endl;
	cout << "Char: " << char(v) << "\n" << endl;


	// 4) записать условие и полное решение уравнения вида 𝑎 ∗ 𝑥 = 𝑏 (a отлично от нуля), причем значения коэффициентов(целые числа) вводит пользователь;
	cout << "№_4" << endl;
	int a, b;
	cout << "Введите коэффициенты a * x = b: " << endl;
	cin >> a >> b;
	cout << "Ответ: " << double(b) / a << endl;


	// Нахождение середины отрезка, заданного целыми координатами концевых точек
	cout << "№_5" << endl;
	double g, i, t;
	cout << "Введите координаты отрезка на прямой: "; cin >> g >> i;
	t = (g + i) / 2;
	cout << "Середина отрезка находится в точке с координатой: " << t << endl;

	cin.get();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
