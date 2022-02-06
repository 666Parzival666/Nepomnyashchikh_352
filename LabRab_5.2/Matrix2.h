#include <iostream>
class Matrix2 
{
private:

	int c, s;

public:

	double* matr = new double;

	// Конструктор матрицы

	void matrix(int a, int b) {
		c = a, s = b;
		matr = new double[a * b]{ 0 };
	}

	void matrix(int a, int b, double* arr) {
		c = a, s = b;
		matr = new double[a * b];
		for (int a = 0; a < s * c; a++) {
			matr[a] = arr[a];
		}
	}
	void input() { //Ввод. Обычный
		std::cout << "enter razmer matrix: ";
		std::cin >> c >> s;
		matr = new double[(c) * (s)];
		std::cout << "enter elements:" << std::endl;
		for (int a = 0; a < s; a++) {
			for (int b = 0; b < c; b++) {
				std::cout << "enter " << "[" << a << "][" << b << "]: ";
				std::cin >> matr[a * c + b];
			}
		}
		std::cout << std::endl;
	}

	void input(int c1, int s1) { //Ввод. Перегрузка.
		c = c1; s = s1;
		matr = new double[(c) * (s)];
		std::cout << "enter elements:" << std::endl;
		for (int a = 0; a < s; a++) {
			for (int b = 0; b < c; b++) {
				std::cout << "enter " << "[" << a << "][" << b << "]: ";
				std::cin >> matr[a * c + b];
			}
		}
		std::cout << std::endl;
	}

	void input(int c1, int s1, double* arr) { //Ввод. Перегрузка.
		c = c1; s = s1;
		matr = new double[(c) * (s)];
		for (int a = 0; a < s * c; a++) {
			matr[a] = arr[a];
		}
		std::cout << std::endl;
	}



	// Вывод матрицы

	void print() {
		for (int a = 0; a < s; a++) {
			for (int b = 0; b < c; b++) {
				std::cout << matr[a * (c)+b] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	void print(double* arr) { //test
		for (int a = 0; a < s; a++) {
			for (int b = 0; b < c; b++) {
				std::cout << arr[a * (c)+b] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	// Сумма матриц

	int matrixsum(double* matr1, double* matr2, int c1, int s2) {
		if (c1 != s2) return 0;
		matr = new double[c1 * s2];
		c = c1; s = s2;
		for (int a = 0; a < c1 * s2; a++) {
			matr[a] = matr1[a] + matr2[a];
		}
		return 1;
	}

	void matrixsum(double* matr1) {
		for (int a = 0; a < this->get_size(); a++) {
			matr[a] += matr1[a];
		}
	}

	int matrixsum(double* matr1, int size) {
		if (this->get_size() != size) return 0;
		for (int a = 0; a < size; a++) {
			matr[a] += matr1[a];
		}
		return 1;
	}



	// Умножение матриц

	int matrixmult(double* matr1, int c1, int s1, double* matr2, int c2, int s2) { //Наша матрица = первая матрица * вторая матрица
		if (c1 == s2) {
			c = c2; s = s1;
			matr = new double[s1 * c2];
			for (int a = 0; a < s1; a++)
				for (int b = 0; b < c2; b++)
				{
					matr[a * c2 + b] = 0;
					for (int d = 0; d < c1; d++)
						matr[a * c2 + b] += matr1[a * c1 + d] * matr2[d * c2 + b];
				}
			return 0;
		}
		else {
			std::cout << "Error of mult: razmer ne raven.";
			c = s = 0;
			return 1;
		}
	}

	int matrixmult(double* matr1, int c1, int s1) { // Наша матрица = наша матрица * другая матрица
		if (c == s1) {
			double* temp_matr = new double[s1 * c]{ 0 };

			for (int a = 0; a < s1; a++) {
				for (int b = 0; b < c; b++) {
					temp_matr[a * c1 + b] = 0;
					for (int d = 0; d < c; d++)
						temp_matr[a * c + b] += matr1[a * c + d] * matr[d * c1 + b];
				}
			}
			matr = new double[s1 * c];
			for (int a = 0; a < s1; a++) {
				for (int b = 0; b < c; b++) {
					matr[a * c + b] = temp_matr[a * c + b];
				}
			}
			return 0;
			s = s1;
		}
		else {
			std::cout << "Error of mult: razmer ne raven.";
			return 1;
		}
	}



	// Умножение матрицы на число

	void mult_by_num(double num) {
		for (int a = 0; a < s * c; a++) {
			matr[a] *= num;
		}
		std::cout << "Multiplied successful with " << num << ".\n\n";
	}



	// Сумма диагонали

	double trace() {
		double sum = 0;
		int dg = this->get_size() / 2;
		for (int a = 0; a < dg; a++) {
			sum += matr[a * dg];
		}
		return sum;
	}


	int get_c() {
		return c;
	}

	int get_s() {
		return s;
	}

	int get_size() {
		return c * s;
	}

	double get_elem(int a, int b) {
		return matr[a * c + b];
	}
};
