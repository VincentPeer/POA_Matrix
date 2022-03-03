//
// Created by dimde on 2/24/2022.
//

#ifndef POA_MATRIX_MATRIX_H
#define POA_MATRIX_MATRIX_H

#include <algorithm>
#include <iostream>


class Matrix {
   const size_t N, M;
   const unsigned n; // todo n -> MODULUS ? (const en majuscul)
   int* tab;

   static void for_each(Matrix& m1, const Matrix& m2, int (*f)(int a, int b));
   static int add(int a, int b);
   static int sub(int a, int b);
   static int multiply(int a, int b);
//	friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
//	friend Matrix* operator+=(const Matrix& lhs, const Matrix& rhs);
public:
   Matrix(size_t N, size_t M, unsigned n);
   Matrix(const Matrix& matrix);
//   int* operator[](int i);
   friend std::ostream& operator<<(std::ostream& lhs, const Matrix& rhs);

//   void* operator new(size_t N, size_t M, unsigned n);
	Matrix operator+(Matrix rhs) const;
	Matrix& operator+=(const Matrix& rhs);
	static Matrix* newSum(const Matrix& a, const Matrix& b);

//   Matrix operator-(const Matrix& rhs);
//   Matrix operator*(const Matrix& rhs);


};


#endif //POA_MATRIX_MATRIX_H
