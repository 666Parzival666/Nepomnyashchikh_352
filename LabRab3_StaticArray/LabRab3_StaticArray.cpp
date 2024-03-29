﻿#include <iostream>

using namespace std;


void puzir(int a[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void CountingSort(char a[], int size)
{
    int max = 255, min = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    int* c = new int[max + 1 - min];
    for (int i = 0; i < max + 1 - min; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        c[a[i] - min] = c[a[i] - min] + 1;
    }
    int i = 0;
    for (int j = min; j < max + 1; j++) {
        while (c[j - min] != 0) {
            a[i] = j;
            c[j - min]--;
            i++;
        }
    }
}

void merge(int a[], int size)
{
    if (size < 2)return;
    merge(a, size / 2);
    merge(&a[size / 2], size - (size / 2));
    int* buf = new int[size];
    int idbuf = 0, idl = 0, idr = size / 2;
    while ((idl < size / 2) && (idr < size))
        if (a[idl] > a[idr])
            buf[idbuf++] = a[idl++];
        else
            buf[idbuf++] = a[idr++];
    while (idl < size / 2) buf[idbuf++] = a[idl++];
    while (idr < size) buf[idbuf++] = a[idr++];
    for (idl = 0; idl < size; idl++) a[idl] = buf[idl];
    delete[]buf;
}


int main()
{
    int choice;
    while (true)
    {
        setlocale(LC_ALL, "Russian");

        cout << "Задания: \n" 
            << "№_1 Сортировка числового массива (длина не более 1000) по возрастанию, по алгоритму пузырьковой системы. \n"
            << "№_2 Сортировка символьного массива (длина не более 1000) по возрастанию, по алгоритму сортировки подсчетом. \n"
            << "№_3 Сортировка числового массива (длина не более 1000) по возрастанию, по алгоритму сортировки слиянием. \n"
            << "Что вы хотите выполнить? \n" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Введите числа (Для завершенния ввода, ввидите -0): \n";
            int nums[1000];
            size_t n = 0;
            for (; n < 1000; n++)
            {
                int input;
                cin >> input;
                if (input == -0)
                {
                    break;
                }
                nums[n] = input;
            }
            puzir(nums, n);
            for (int l = 0; l < n; ++l)
                cout << nums[l] << ' ';
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "Введите буквы(введите @, если хотите завершить ввод): \n";
            char a[1000];
            size_t n = 0;
            for (; n < 1000; n++)
            {
                char input;
                cin >> input;
                if (input == '@')
                {
                    break;
                }
                a[n] = input;
            }
            CountingSort(a, n);
            for (int l = 0; l < n; ++l)
                cout << a[l] << ' ';
            cout << endl;
            break;
        }
        case 3:
            cout << "Введите числа (введите -0, если хотите завершить ввод): \n";
            int nums[1000];
            size_t n = 0;
            for (; n < 1000; n++)
            {
                int input;
                cin >> input;
                if (input == -0)
                {
                    break;
                }
                nums[n] = input;
            }
            merge(nums, n);
            for (int l = 0; l < n; ++l)
                cout << nums[n - 1 - l] << ' ';
            cout << endl;
            break;


        }
    }
}
