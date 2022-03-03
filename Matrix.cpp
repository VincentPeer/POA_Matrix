//
// Created by dimde on 2/24/2022.
//

#include "Matrix.h"
#include "algorithm"

using namespace std;

Matrix::Matrix(size_t N, size_t M, unsigned n)  : N(N), M(M), n(n) {
   tab = new int[N * M];
   for (size_t i = 0; i < N * M; ++i) {
      *(tab + i) = rand() / (RAND_MAX + 1) * n;
   }

}

ostream& operator<<(ostream& lhs, const Matrix& rhs) {
	for (size_t i = 0; i < rhs.N * rhs.M; ++i) {
		if(i % rhs.M == 0 && i)
			cout << endl;
		cout << rhs.tab[i];
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