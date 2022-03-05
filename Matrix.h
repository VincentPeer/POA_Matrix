//
// Created by dimde on 2/24/2022.
//

#ifndef POA_MATRIX_MATRIX_H
#define POA_MATRIX_MATRIX_H

#include <algorithm>
#include <iostream>


class Matrix {
   const size_t N, M;
   const unsigned MODULUS;
   int** tab;

   void allocate();
	friend std::ostream& operator<<(std::ostream& lhs, const Matrix& rhs);
//	friend Matrix* operator+(const Matrix& lhs, const Matrix& rhs);
	static int addElement(int a, int b);
	static int subElement(int a, int b);
	static int multiplyElement(int a, int b);
	static void for_each(Matrix& m1, const Matrix& m2, int (*f)(int a, int b));
public:
   Matrix(size_t N, size_t M, unsigned n);
   Matrix(const Matrix& matrix);
	Matrix& add(const Matrix& rhs);
	Matrix add(Matrix rhs) const;
	Matrix* addDynamic(const Matrix& rhs) const;


};


#endif //POA_MATRIX_MATRIX_H
