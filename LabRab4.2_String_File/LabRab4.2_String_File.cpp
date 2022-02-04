#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

string file_format(const string file_path_full) {
	size_t pos = file_path_full.rfind('.');
	if (pos <= 0) {
		return "";
	}
	return file_path_full.substr(pos + 1, string::npos);
}

void task1() {
	string file_path_full;

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full;

	cout << file_format(file_path_full) << endl; // Вывод расширения из полного расположения файла
}


string file_name(const string file_path_full) {
	size_t pos = file_path_full.rfind('\\');
	if (pos <= 0) {
		return "";
	}
	size_t pos2 = file_path_full.rfind('.');
	if (pos2 <= 0) {
		return "";
	}
	return file_path_full.substr(pos + 1, pos2 - pos - 1);
}


void task2() {
	string file_path_full; // Полное расположение файла

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full; // Ввод полного расположения файла

	cout << file_name(file_path_full) << endl; // Вывод названия из полного расположения файла
}


string file_path(const string file_path_full) {
	size_t pos = file_path_full.rfind('\\');
	if (pos <= 0) {
		return "";
	}
	return file_path_full.substr(0, pos + 1);
}


void task3() {
	string file_path_full; // Полное расположение файла

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full; // Ввод полного расположения файла

	cout << file_path(file_path_full) << endl; // Вывод расположения из полного расположения файла
}


char file_disk(const string file_path_full) {
	return file_path_full[0];
}


void task4() {
	string file_path_full;

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full;

	cout << file_disk(file_path_full) << endl;
}


bool file_rename(const string file_path_full, const string new_file_path_full) {
	return rename(file_path_full.c_str(), new_file_path_full.c_str());
}


void task5() {
	string file_path_full;
	string new_file_name;

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full; // Ввод полного расположения файла
	cout << "Введите новое имя файл: " << endl;
	cin >> new_file_name; // Ввод нового имени файла

	if (!file_rename(file_path_full, file_path(file_path_full) + new_file_name + '.' + file_format(file_path_full))) {
		cout << "Файл был успешно переименован" << endl;
	}
	else {
		cout << "Не удалось переименовать файл" << endl;
	}
}


bool file_copy(const string file_path_full) {


	ifstream fin(file_path_full);

	if (!fin.is_open()) {
		return false;
	}



	ofstream fin_copy(file_path(file_path_full) + file_name(file_path_full) + "_copy." + file_format(file_path_full)); // Создали копию файл для записи

	if (!fin_copy.is_open()) { // Если файл не открыт вернуть false
		return false;
	}



	string line;

	while (fin) {
		getline(fin, line);
		if (fin.fail()) {
			break;
		}
		fin_copy << line << '\n';
	}



	fin.close(); // Закрываем файл
	fin_copy.close(); // Закрываем копию файла

	return true;
}


void task6() {
	string file_path_full;

	cout << "Введите полное расположение файла: " << endl;
	cin >> file_path_full;

	if (file_copy(file_path_full)) {
		cout << "Копия файла была успешна создана" << endl;
	}
	else {
		cout << "Не удалось создать копию файла" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	while (true) {
		cout << "Что вы хотите выполнить? \n"
			<< "1. По введенному полному расположению файла получить расширение\n"
			<< "2. По введенному полному расположению файла получить название\n"
			<< "3. По введенному полному расположению файла получить расположение\n"
			<< "4. По введенному полному расположению файла получить название диска\n"
			<< "5. По введенному полному расположению файла и новому имени переименовать файл\n"
			<< "6. По введенному полному расположению файла создать копию файла (имя копии получается приписыванием  «_copy» к имени файла)\n"
			<< "7. Выход\n";
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
		case 5: {

			task5();
			break;
		}
		case 6: {

			task6();
			break;
		}
		case 7: {

			return 0;
			break;
		}
		default: {
			cout << "Произошла ошибка" << endl;
		}
		}
	}
}