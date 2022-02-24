//
// Created by dimde on 2/24/2022.
//

#include "Matrix.h"


Matrix::Matrix(size_t N, size_t M, unsigned n)  : N(N), M(M), n(n) {
   tab = new int[N * M];
   for (size_t i = 0; i < N * M; ++i) {
      *(tab + i) = rand() / (RAND_MAX + 1) * n;
   }

}