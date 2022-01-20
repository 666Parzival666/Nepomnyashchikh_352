#include <iostream>;
#include <cstring>;
using namespace std;
bool checkstr(char s[100]) 
{
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) 
	{
		if (s[i] != s[len - i - 1]) 
		{
			return false;

		}
	}
	return true;
}
void task1() 
{
	char s[100];
	cout << "Введите строку: ";
	cin >> s;
	if (checkstr(s)) 
	{
		cout << "Строка является полиндромом" << endl;
	}
	else 
	{
		cout << "Строка не является полиндромом" << endl;
	}
}
int find_substring1(const char* str_for_search_in, const char* substring, int start_position)
{
	int lenAllStr = 0;
	while (str_for_search_in[lenAllStr] != '\0')
		lenAllStr++;
	int lenSub = 0;
	while (substring[lenSub] != '\0')
		lenSub++;

	unsigned int i, j;
	int number = 0;
	for (i = start_position; i < lenAllStr - lenSub + 1; i++) {
		j = 0;
		while ((j < lenSub) && (substring[j] == str_for_search_in[i + j])) {
			j = j + 1;
		}

		if (j == lenSub)
		{
			return i;
		}

	}

	return number;


}
int* find_substring2(const char* str_for_search_in, const char* substring)
{
	int* mas = new int;

	int lenAllStr = 0;
	while (str_for_search_in[lenAllStr] != '\0')
		lenAllStr++;
	int lenSub = 0;
	while (substring[lenSub] != '\0')
		lenSub++;

	int i, j;
	int number = 0;
	for (i = 0; i < lenAllStr - lenSub + 1; i++) {
		j = 0;
		while ((j < lenSub) && (substring[j] == str_for_search_in[i + j])) {
			j = j + 1;
		}

		if (j == lenSub)
		{
			mas[number] = i;
			number++;
			cout << i << " ";
		}

	}

	return mas;

}
void encrypt(char* str_for_encrypt, int key)
{
	for (int i = 0; i < strlen(str_for_encrypt); i++) {
		if ('a' <= str_for_encrypt[i] && str_for_encrypt[i] <= 'z') {
			if (str_for_encrypt[i] + key > 'z') // Если происходит выход за пределы алфавита
				str_for_encrypt[i] = 'z' - str_for_encrypt[i] + 'a' + key - 1; // Переносимся в начало и применяем ключ
			else str_for_encrypt[i] += key;
		}
		else if ('A' <= str_for_encrypt[i] && str_for_encrypt[i] <= 'Z') { // Тот же принцип, но для верхнего регистра
			if (str_for_encrypt[i] + key > 'Z')
				str_for_encrypt[i] = 'Z' - str_for_encrypt[i] + 'A' + key - 1;
			else str_for_encrypt[i] += key;
		}
		else if (str_for_encrypt[i] == ' ');
	}
	return;
} 
void task4()
{
	char s[100];
	char str = ' " ';
	cout << "Введите строку: " << endl;
	cin.getline(s, 100);
	cin.ignore();
	int len = strlen(s);
	for (int k = 0; k < len; k++)
	{
		if (s[k] == str)
		{
			for (int i = k + 1; i < len; i++)
			{
				if (s[i] != str)
				{
					cout << s[i] << endl;
				}
			}
		}
	}
}
int main()
{
	setlocale(0, "");
	int choice = 0;
	while (true) 
	{
		cout << "№1.Палиндром" << endl;
		cout << "№2.Поиск подстроки" << endl;
		cout << "№3.Шифр Цезаря" << endl;
		cout << "№4.Найти слова в кавычках" << endl;
		cout << "№5.Выход" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1: 
			{
				task1();
				break;
			}
			case 2: 
			{
				char text3[255];
				cout << "Введите текст\n";
				std::cin.ignore();
				cin.getline(text3, 255);
				char t2[255];
				cout << "Введите подстроку\n";
				cin >> t2;

				int* m;
				m = find_substring2(text3, t2);
				cout << endl;

				break;
			}
			case 3: 
			{
				int key;
				char string[255];

				cout << "Введите текст: "; cin.ignore(); cin.getline(string, 255);
				cout << "Введите ключ: "; cin >> key;

				encrypt(string, key);
				char* str_for_encrypt = new char[strlen(string) + 1];
				str_for_encrypt = string + '\0';
				cout << "Encrypted string: " << str_for_encrypt << endl;
				cout << endl;

				break;
			}
			case 4: 
			{
				task4();
				break;
			}
			default: 
			{
				return 0;
			}
		}
	}
}