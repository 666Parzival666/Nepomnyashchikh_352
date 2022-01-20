#include <iostream>
#include <map>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string input;
    map <string, int> map1;

    double count = 0;
    int j = 1;
    cout << "Введите текст: ";
    while (cin >> input)
    {
        count++;
        if (map1.find(input) == map1.end())
        {
            map1.insert(pair<string, int>(input, j));
        }
        else
        {
            map1[input] += 1;
        }
    }

    for (auto i = map1.begin(); i != map1.end(); i++)
    {
        cout << i->first << " " << (double(i->second / count) * 100) << "%" << endl;
    }
}