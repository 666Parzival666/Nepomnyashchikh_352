#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	stack <char> steck;
	string text;
	cout << "Введите скобки: ";
	cin >> text;

	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == '(' || text[i] == '[' || text[i] == '{')
		{
			steck.push(text[i]);
		}
		else if (text[i] == ')' || text[i] == ']' || text[i] == '}')
		{
			if (steck.empty())
			{
				cout << "Не правильно" << endl;
				return 1;
			}


			switch (text[i])
			{
			case ')':
				if (steck.top() == '(')
				{
					steck.pop();
				}
				else
				{
					cout << "Не правильно" << endl;
					return 1;
				}
				break;


			case ']':
				if (steck.top() == '[')
				{
					steck.pop();
				}
				else
				{
					cout << "Не правильно" << endl;
					return 1;
				}
				break;


			case '}':
				if (steck.top() == '{')
				{
					steck.pop();
				}
				else
				{
					cout << "Не правильно" << endl;
					return 1;
				}
				break;
			}
		}
	}
	cout << "Правильно";
	return 0;
}