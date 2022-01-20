#include <iostream>
#include <queue>

using namespace std;

int counting(int a) 
{
    while (a % 2 == 0) 
    {
        a = a / 2;
    }
    while (a % 3 == 0) 
    {
        a = a / 3;
    }
    while (a % 5 == 0) 
    {
        a = a / 5;
    }
    return a;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    queue <int> q;
    int n;
    int num = 2;
    int x = 0;

    cout << "Введите ко-во чисел: "; cin >> n;  //Просим пользователя ввести количество n чисел

    while (x < n) 
    {
        if (counting(num) == 1) 
        {
            q.push(num);
            x++;
        }
        num++;
    }

    for (int i = 0; i < n; i++) 
    {
        cout << q.front() << ' ';
        q.pop();
    }

}