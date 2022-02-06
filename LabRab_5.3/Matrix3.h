#include <iostream>
#pragma once
#ifndef Matrix_peremennaya
#define Matrix_peremennaya
class Matrix3 {
private:
	short n;
	double* matrix;
public:
	Matrix3();
	Matrix3(const Matrix3& temp);

	~Matrix3();

	double trace() const;
	double det() const;
	void input();
	void input(int size);
	void print() const;
	short get_columns() const;

	double get_elem(short i, short j) const;
	void set_elem(short i, short j, double num);

	friend std::istream& operator>>(std::istream& in, Matrix3& matr1);
	friend std::ostream& operator<<(std::ostream& out, const Matrix3& matr1);
	friend Matrix3 operator+(const Matrix3& matr1, const Matrix3& matr2);
	friend Matrix3 operator-(const Matrix3& matr1, const Matrix3& matr2);
	friend Matrix3 operator-(const Matrix3& matr1);
	friend Matrix3 operator*(const Matrix3& matr1, const Matrix3& matr2);
	friend Matrix3 operator*(const Matrix3& matr1, const int num);
	void operator+=(const Matrix3& matr2);
	void operator-=(const Matrix3& matr2);
};

#endif
