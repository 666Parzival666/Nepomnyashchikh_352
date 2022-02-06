#include "Matrix3.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Matrix3::Matrix3() {
	this->n = 0;
	this->matrix = nullptr;
}

Matrix3::Matrix3(const Matrix3& temp) {
	this->n = temp.n;

	if (this->matrix != nullptr) {
		delete[]this->matrix;
	}

	this->matrix = new double[3 * this->n];
	for (int i = 0; i < 3 * this->n; i++) {
		this->matrix[i] = temp.matrix[i];
	}
}

Matrix3::~Matrix3() {
	if (this->matrix != nullptr) {
		delete[]this->matrix;
	}
}

double Matrix3::trace() const {
	double sumD = 0;
	for (int i = this->n; i < 2 * this->n; i++) {
		sumD += this->matrix[i];
	}
	return sumD;
}

double Matrix3::det() const {
	double l = this->get_elem(0, 0);
	double c = this->get_elem(0, 1);
	double u = c / l;
	double lam = this->get_elem(1, 0);
	double detNum = l;

	for (int i = 1; i < n - 1; i++) {
		l = this->get_elem(i, i) - lam * u;
		detNum *= l;
		c = this->get_elem(i, i + 1);
		u = c / l;
		lam = this->get_elem(i + 1, i);
	}

	l = this->get_elem(n - 1, n - 1) - lam * u;
	detNum *= l;

	return detNum;
}

void Matrix3::input() {
	short size;

	cout << "¬ведите размер матрицы: ";
	cin >> size;

	if (this->matrix != nullptr) {
		delete[]this->matrix;
	}

	this->n = size;
	this->matrix = new double[3 * size];

	for (int i = 0; i < 3 * size; i++) {
		if (i != size - 1 && i != 2 * size) {
			cin >> this->matrix[i];
		}
	}
	this->matrix[size - 1] = 0;
	this->matrix[2 * size] = 0;
}

void Matrix3::input(int size) {
	this->n = size;

	if (this->matrix != nullptr) {
		delete[]this->matrix;
	}

	this->matrix = new double[3 * size];

	for (int i = 0; i < 3 * size; i++) {
		this->matrix[i] = i + 1;
	}
	this->matrix[size - 1] = 0;
	this->matrix[2 * size] = 0;
}

void Matrix3::print() const {
	for (int i = 0; i < this->n; i++) {
		for (int j = 0; j < this->n; j++) {
			cout << this->get_elem(i, j) << "\t";
		}
		cout << endl;
	}
}

short Matrix3::get_columns() const {
	return this->n;
}

double Matrix3::get_elem(short i, short j) const {
	if (i >= 0 && j >= 0 && i < this->n && j < this->n) {
		if (i == j) {
			return this->matrix[this->n + i];
		}
		else if (i == j + 1) {
			return this->matrix[2 * this->n + i];
		}
		else if (i + 1 == j) {
			return this->matrix[i];
		}
		else {
			return 0;
		}
	}
	cout << "\nIndex error in get_elem.\n";
	return 0;
}

void Matrix3::set_elem(short i, short j, double num) {
	if (i >= 0 && j >= 0 && i < this->n && j < this->n) {
		if (i == j) {
			this->matrix[this->n + i] = num;
		}
		else if (i == j + 1) {
			this->matrix[2 * this->n + i] = num;
		}
		else if (i + 1 == j) {
			this->matrix[i] = num;
		}
	}
}

std::istream& operator>>(std::istream& in, Matrix3& matr1) {
	short size;

	cout << "¬ведите размер матрицы: ";
	in >> size;

	if (matr1.matrix != nullptr) {
		delete[]matr1.matrix;
	}

	matr1.n = size;
	matr1.matrix = new double[3 * size];

	for (int i = 0; i < 3 * size; i++) {
		if (i != size - 1 && i != 2 * size) {
			in >> matr1.matrix[i];
		}
	}
	matr1.matrix[size - 1] = 0;
	matr1.matrix[2 * size] = 0;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix3& matr1) {
	for (int i = 0; i < matr1.n; i++) {
		for (int j = 0; j < matr1.n; j++) {
			out << matr1.get_elem(i, j) << "\t";
		}
		out << std::endl;
	}
	return out;
}

Matrix3 operator+(const Matrix3& matr1, const Matrix3& matr2) {
	Matrix3 matrSum(matr2);

	for (int i = 0; i < 3 * matr2.n; i++) {
		matrSum.matrix[i] += matr1.matrix[i];
	}

	return matrSum;
}

Matrix3 operator-(const Matrix3& matr1, const Matrix3& matr2) {
	Matrix3 matrSum(matr2);

	for (int i = 0; i < 3 * matr2.n; i++) {
		matrSum.matrix[i] -= matr1.matrix[i];
	}

	return matrSum;
}

Matrix3 operator-(const Matrix3& matr1) {
	Matrix3 matrOtr(matr1);

	for (int i = 0; i < 3 * matr1.n; i++) {
		matrOtr.matrix[i] *= -1;
	}

	return matrOtr;
}

Matrix3 operator*(const Matrix3& matr1, const Matrix3& matr2) {
	Matrix3 matrMult(matr2);

	for (int i = 0; i < 3 * matr1.n; i++) {
		matrMult.matrix[i] = 0;
	}

	for (int i = 0; i < matr1.n; i++) {
		for (int j = 0; j < matr2.n; j++) {
			for (int k = 0; k < matr1.n; k++) {
				matrMult.set_elem(i, j, matrMult.get_elem(i, j) + matr1.get_elem(i, k) * matr2.get_elem(k, j));
			}
		}
	}

	return matrMult;
}

Matrix3 operator*(const Matrix3& matr1, const int num) {
	Matrix3 matrUmn(matr1);

	for (int i = 0; i < 3 * matrUmn.n; i++) {
		matrUmn.matrix[i] *= num;
	}

	return matrUmn;
}

void Matrix3::operator+=(const Matrix3& matr2) {
	// *this = this->sum(temp);
	for (int i = 0; i < 3 * this->n; i++) {
		this->matrix[i] += matr2.matrix[i];
	}
}

void Matrix3::operator-=(const Matrix3& matr2) {
	for (int i = 0; i < 3 * this->n; i++) {
		this->matrix[i] -= matr2.matrix[i];
	}
}
