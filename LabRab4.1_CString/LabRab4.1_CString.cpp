#include <iostream>;
#include <cstring>;
using namespace std;
bool checkstr(char s[100]) {
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1]) {
			return false;

		}
	}
	return true;
}
void task1() {
	char s[100];
	cout << "Введите строку: ";
	cin >> s;
	if (checkstr(s)) {
		cout << "Строка является полиндромом" << endl;
	}
	else {
		cout << "Строка не является полиндромом" << endl;
	}
}
void task2() {
	string s, ss;
	int n = 0, p = 0;
	cout << "Введите строку: ";
	cin >> s;
	cout << "Введите подстроку: ";
	cin >> ss;
	while ((p = s.find(ss, p)) != s.npos) {
		++n;
		++p;
	}
	cout << "Подстрока '" << ss << "' встречается в строке '" << s << "' " << n << " раз" << endl;
}
void task3() {
	int k;
	char buff[50];
	cout << "Введите сообщение : ";
	cin >> buff;
	cout << "Введите кол-во букв для сдвига : ";
	cin >> k;
	for (int i = 0; i < strlen(buff); i++)
		buff[i] += k;
	cout << "Шифр : " << buff << endl;

	cout << "Расшифровка : ";
	for (int i = 0; i < strlen(buff); i++)
		buff[i] -= k;

	cout << buff << endl;
}
void task4() {
	char s[100];
	char str = ' " ';
	cout << "Введите строку: " << endl;
	cin.getline(s, 100);
	cin.ignore();
	int len = strlen(s);
	for (int k = 0; k < len; k++) {
		if (s[k] == str) {
			for (int i = k + 1; i < len; i++) {
				if (s[i] != str) {
					cout << s[i] << endl;
				}
			}
		}
	}
}
int main() {
	setlocale(0, "");
	int choice = 0;
	while (true) {
		cout << "№1.Палиндром" << endl;
		cout << "№2.Поиск подстроки" << endl;
		cout << "№3.Шифр" << endl;
		cout << "№4.Найти слова в кавычках" << endl;
		cout << "№5.Выход" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			task1();
			break;
		}
		case 2: {
			task2();
			break;
		}
		case 3: {
			task3();
			break;
		}
		case 4: {
			task4();
			break;
		}
		default: {
			return 0;
		}
		}
	}
}