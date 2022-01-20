#include <iostream>
#include <deque>

using namespace std;
setlocale(LC_ALL, "Russian");

bool palindrom() {
    string S;
    deque <char> check;
    cout << "Введите строчку ";
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        check.push_back(S[i]);
    }
    while (!check.empty()) {
        if (check.size() == 1) break;
        if (check.front() == check.back()) {
            check.pop_back();
            check.pop_front();
        }
        else {
            cout << "Не является полиндромом" << endl;
            return false;
        }
    }
    cout << "Является полиндромом" << endl;
    return true;
}

int main() {
    int N;
    while (true) {
        cout << "Выберите номер задания ";
        cin >> N;
        switch (N) {
        case 1:
            palindrom();
            break;
        case 2:
            break;
        case 3:
            cout << "Всего доброго" << endl;
            return 0;
        default:
            cout << "Ошибка" << endl;
            break;
        }
    }
    return 0;
}