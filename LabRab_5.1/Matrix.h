#include <iostream>;
class Matrix
{
private:
	int c, s;
public:
	double* matr = new double;
	void input() {
		std::cout << "Enter size of matrix:" << std::endl;
		std::cin >> c >> s;
		matr = new double[(c) * (s)];
		std::cout << "Enter elements:" << std::endl;
		for (int a = 0; a < s; a++) {
			for (int b = 0; b < c; b++) {
				std::cout << "Enter" << "[" << a << "][" << b << "]: ";
				std::cin >> matr[a * c + b];
			}
		}
		std::cout << std::endl;
	}
	void print() {
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < c; j++) {
				std::cout << matr[i * c + j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
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
	double get_elem(int i, int j) {
		return matr[i * c + j];
	}
	int matrixsum(double* matr1, double* matr2, int c1, int s2) {
		if (c1 != s2) {
			return 0;
		}
		matr = new double[c1 * s2];
		c = c1, s = s2;
		for (int i = 0; i < c1 * s2; i++) {
			matr[i] = matr1[i] + matr2[i];
		}
		return 1;
	}
	int matrixmult(double* matr1, int c1, int s1, double* matr2, int c2, int s2) {
		if (c1 == s2) {
			c = c1; s = s2;
			matr = new double[s * c];
			for (int i = 0; i < s1; i++)
				for (int j = 0; j < c2; j++)
				{
					matr[i * c2 + j] = 0;
					for (int k = 0; k < c1; k++)
						matr[i * c2 + j] += matr1[i * c1 + k] * matr2[k * c2 + j];
				}
			return 0;
		}
		else {
			std::cout << "Error multi: razmeri ne ravni.";
			c = s = 0;
			return 1;
		}
	}

	void mult_by_num(double num) {
		for (int i = 0; i < s * c; i++) {
			matr[i] *= num;
		}
		std::cout << "Multiplied successful with " << num << ".\n";
	}

	double trace(double* matr, int size) {
		double sum = 0;
		for (int i = 0; i < size; i++) {
			sum += matr[i * size + i];
		}
		return sum;
	}
};