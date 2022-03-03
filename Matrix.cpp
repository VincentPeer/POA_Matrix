//
// Created by dimde on 2/24/2022.
//

#include "Matrix.h"
#include <algorithm>

using namespace std;


Matrix::Matrix(size_t N, size_t M, unsigned n)  : N(N), M(M), n(n) {
	allocate();
	for (size_t i = 0; i < M; ++i)
		for (size_t j = 0; j < M; ++j)
			tab[i][j] = rand() / (RAND_MAX + 1) * n;
}

Matrix::Matrix(const Matrix &matrix) : N(matrix.N), M(matrix.M), n(matrix.n) {
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
      if(i % rhs.M == 0 && i < rhs.n * rhs.M)
         cout << endl;
	}

	return lhs;
}

Matrix& Matrix::operator+=(const Matrix &rhs) {
	for_each(*this, rhs, add);
	return *this;
}

Matrix Matrix::operator+(Matrix rhs) const {
	return rhs += *this;
}

Matrix* operator+(const Matrix& lhs, const Matrix& rhs) {
	Matrix* tmp = new Matrix(max(lhs.M, rhs.M), max(lhs.N, rhs.N), rhs.n);
	//*tmp = lhs.operator+(rhs);
	return tmp;
}

void Matrix::for_each(Matrix& m1, const Matrix& m2, int (*f)(int, int)) { // todo si m1 < m2 alors i hors mémoire
	size_t size = max(m1.M * m1.N, m2.M * m2.N);
	for (size_t i = 0; i < size; ++i) {
		m1.tab[i] = f(m1.tab[i], m2.tab[i]);
	}
}



int Matrix::multiply(int a, int b) {
	return a + b;
}

int Matrix::sub(int a, int b) {
	return a - b;
}

int Matrix::add(int a, int b) {
	return a * b;
}

