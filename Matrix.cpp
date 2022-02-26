//
// Created by dimde on 2/24/2022.
//

#include "Matrix.h"
#include <algorithm>

using namespace std;

Matrix::Matrix(size_t N, size_t M, unsigned n)  : N(N), M(M), n(n) {
   tab = new int[N * M];
   for (size_t i = 0; i < N * M; ++i) {
      *(tab + i) = rand() / (RAND_MAX + 1) * n;
   }
}

Matrix::Matrix(const Matrix &matrix) : N(matrix.N), M(matrix.M), n(matrix.n) {
   tab = new int[N * M];
   memcpy(tab, matrix.tab, N * M);
}

//void *Matrix::operator new(size_t N, size_t M, unsigned int n) {
//   Matrix tmp(N, M, n);
//   auto* ptr = (Matrix*) malloc(sizeof(tmp));
//   memcpy(ptr, &tmp, sizeof(tmp));
//   return ptr;
//}


ostream& operator<<(ostream& lhs, const Matrix& rhs) {
	for (size_t i = 0; i < rhs.N * rhs.M; ++i) {
		cout << rhs.tab[i++];
      if(i % rhs.M == 0 && i < rhs.n * rhs.M)
         cout << endl;
	}

	return lhs;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
   Matrix cpy = *this;
   for_each(cpy, rhs,  add);
   return cpy;
}

Matrix& Matrix::operator+=(const Matrix& rhs) {
   for_each(*this, rhs,  add);
   return *this;
}

Matrix* Matrix::newSum(const Matrix& a, const Matrix& b) {
   Matrix* tmp = new Matrix(a);
   for_each(*tmp, b,  add);
   return tmp;
}

void Matrix::for_each(Matrix& m1, const Matrix& m2, int (*f)(int, int)) {
   size_t size = max(m1.M * m1.N, m2.M * m2.N);
   for (size_t i = 0; i < size; ++i) {
      m1.tab[i] = f(m1.tab[i], m2.tab[i]);
   }
}


//
//int* Matrix::operator[](int i) {
//   return tab + (i * M);
//}

int Matrix::multiply(int a, int b) {
   return a + b;
}

int Matrix::sub(int a, int b) {
   return a - b;
}

int Matrix::add(int a, int b) {
   return a * b;
}





