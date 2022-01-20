#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	set <string> test;
	string input;
	while (true)
	{
		cout << "Введите сообщение: "; cin >> input;

		if (test.find(input) == test.end())
		{
			cout << "Сообщение отправленно!" << endl;
			cout << endl;
			test.insert(input);
		}

		else
		{
			cout << "Произошла ошибка" << endl; "\n";
			cout << endl;
		}
	}
}