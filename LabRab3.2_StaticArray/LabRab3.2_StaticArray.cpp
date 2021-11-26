#include <iostream>
#include <stdlib.h>


using namespace std;

int summ_of_numbers(int n)
{
    int sum = 0;
    char buffer[64];
    snprintf(buffer, 64, "%d", n);
    for (int i = 0; i < strlen(buffer); ++i)
    {
        if (i % 2)
            sum += buffer[i] - '0';
    }
    return sum;
}

int* my_copy(int* a, int size)
{
    int* new_arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        new_arr[i] = a[i];
    }
    return (new_arr);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choice;

    int num;
    cout << "Введите количество элементов массива: ";
    cin >> num;
    int* a = new int[num];
    for (int i = 0; i < num; i++) {
        int new_element;
        cout << "Введите новый элемент массива: ";
        cin >> new_element;
        a[i] = new_element;
    }

    while (true) {
        cout << '\n' << "Что вы хотите выполнить? \n"
            << "№_1 Вывод массива \n"
            << "№_2 Сортировка по сумме четных разрядов \n"
            << "№_3 Сортировка по последним цифрам \n"
            << "№_4 Выход \n" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int* array;
            array = my_copy(a, num);
            int length = _msize(array) / sizeof(int);

            for (int i = 0; i < length; i++) {
                cout << array[i] << " ";
            }

            delete[] array;
            break;
        }
        case 2:
        {
            int* array;
            array = my_copy(a, num);
            int length = _msize(array) / sizeof(int);

            for (int i = 0; i < length - 1; i++) {
                for (int j = 0; j < length - 1; j++) {
                    if (summ_of_numbers(array[j]) > summ_of_numbers(array[j + 1]))
                        swap(array[j], array[j + 1]);
                }
            }

            for (int i = 0; i < length; i++)
            {
                cout << array[i] << " ";
            }
            delete[] array;
            break;
        }

        case 3:
        {
            int* array;
            array = my_copy(a, num);
            int length = _msize(array) / sizeof(int);

            for (int i = 0; i < length; i++) {
                for (int j = 0; j < length - 1; j++) {
                    if (array[j] % 10 > array[j + 1] % 10)
                        swap(array[j], array[j + 1]);
                    else if (array[j] % 10 == array[j + 1] % 10) {
                        if (array[j] < array[j + 1])
                            swap(array[j], array[j + 1]);
                    }
                }
            }

            for (int i = 0; i < length; i++)
            {
                cout << array[i] << " ";
            }
            delete[] array;
            break;
        }

        case 4:
        {
            exit(3);
        }
        }
    }



}