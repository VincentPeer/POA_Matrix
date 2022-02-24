//
// Created by dimde on 2/24/2022.
//

#include "Matrix.h"

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