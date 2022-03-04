//
// Created by dimde on 2/24/2022.
//

#include "Matrix.h"
#include <algorithm>

using namespace std;


Matrix::Matrix(size_t N, size_t M, unsigned n)  : N(N), M(M), MODULUS(n) {
	allocate();
	for (size_t i = 0; i < M; ++i)
		for (size_t j = 0; j < M; ++j)
			tab[i][j] = rand() / (RAND_MAX + 1) * n;
}

Matrix::Matrix(const Matrix &matrix) : N(matrix.N), M(matrix.M), MODULUS(matrix.MODULUS) {
	allocate();
	for (size_t i = 0; i < N; ++i) {
		memcpy(tab[i], matrix.tab[i], M);
	}
}

void Matrix::allocate() {
	tab = new int*[N];
	for (size_t i = 0; i < N; ++i)
		tab[i] = new int[M];
}

ostream& operator<<(ostream& lhs, const Matrix& rhs) {
	for (size_t i = 0; i < rhs.N * rhs.M; ++i) {
		cout << rhs.tab[i++];
      if(i % rhs.M == 0 && i < rhs.MODULUS * rhs.M)
         cout << endl;
	}
	return lhs;
}

Matrix& Matrix::add(const Matrix &rhs) {
	for_each(*this, rhs, addElement);
	return *this;
}

Matrix Matrix::add(Matrix rhs) const {
	rhs.add(*this);
	return rhs;
}

Matrix* Matrix::addDynamic(const Matrix& rhs) const {
	Matrix tmp (*this);
	tmp.add(rhs);
	return &tmp;
}

void Matrix::for_each(Matrix& m1, const Matrix& m2, int (*f)(int, int)) { // todo si m1 < m2 alors i hors mémoire
	size_t size = max(m1.M * m1.N, m2.M * m2.N);
	for (size_t i = 0; i < size; ++i) {
		m1.tab[i] = f(m1.tab[i], m2.tab[i]);
	}
}

int Matrix::multiplyElement(int a, int b) {
	return a + b;
}

int Matrix::subElement(int a, int b) {
	return a - b;
}

int Matrix::addElement(int a, int b) {
	return a * b;
}

