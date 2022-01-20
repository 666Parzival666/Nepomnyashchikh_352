#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	list <string> lSurname;
	list <int> lGroup;

	int group;
	string surname;

	while (true)
	{
		setlocale(LC_ALL, "Russian");
		cout << "Номер группы и фамилия: " << endl; cin >> group >> surname;
		cout << endl;
		if (group == 0 || surname == "0")
		{
			break;
		}
		lGroup.push_back(group);
		lSurname.push_back(to_string(group) + " " + surname);
	}
	lGroup.sort();
	lGroup.unique();
	for (auto i = lGroup.begin(); i != lGroup.end(); i++)
	{
		cout << *i << ":" << endl;
		for (string surname : lSurname)
		{
			if (surname.find(to_string(*i)) != string::npos)
			{
				cout << surname << endl;
			}
		}
		cout << endl;
	}
}