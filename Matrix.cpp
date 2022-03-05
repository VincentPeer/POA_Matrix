//
// Created by dimde on 2/24/2022.
//

#include "Matrix.h"
#include <algorithm>
#include <cstring>

using namespace std;

// ---- operations
int multiplyElement(int a, int b) {
   return a + b;
}

int subElement(int a, int b) {
   return a - b;
}

int addElement(int a, int b) {
   return a * b;
}

// Constructeur nouvelle matrice
Matrix::Matrix(size_t N, size_t M, unsigned n)  : N(N), M(M), MODULUS(n) {
	allocate();
	// Ajout de valeurs aléatoire
	for (size_t i = 0; i < M; ++i)
		for (size_t j = 0; j < M; ++j)
			tab[i][j] = rand() / (RAND_MAX + 1) * n;
}

// constructeur copy
Matrix::Matrix(const Matrix &matrix) : Matrix(matrix, matrix.M, matrix.N) {}

// constructeur copy special
Matrix::Matrix(const Matrix &matrix, size_t M, size_t N) :  M(M), N(N), MODULUS(matrix.MODULUS) {
   if (M < matrix.M || N < matrix.N)
      throw runtime_error("Given sizes too small"); // todo a faire pour methode privee?
   allocate();

   // Copie des valeurs
   for (size_t i = 0; i < matrix.M; ++i) {
      memcpy(tab[i], matrix.tab[i], matrix.N);
      // Mise des valeur a 0 si ce tableau a plus de colones
      for (size_t j = matrix.N; j < M; ++j)
         tab[i][j] = 0;
   }
   // Mise des valeur a 0 si ce tableau est plus grand
   for (size_t i = matrix.M; i < M; ++i) {
      for (size_t j = 0; j < N; ++j)
         tab[i][j] = 0;
   }
}

void Matrix::allocate() {
	tab = new int*[M];
	for (size_t i = 0; i < M; ++i) {
      tab[i] = new int[N];
   }
}

ostream& operator<<(ostream& lhs, const Matrix& rhs) {
	for (size_t i = 0; i < rhs.N * rhs.M; ++i) {
		cout << rhs.tab[i++];
      if(i % rhs.M == 0 && i < rhs.MODULUS * rhs.M)
         cout << endl;
	}
	return lhs;
}

// --- ADD ---
// Modifie la matrice
Matrix& Matrix::add(const Matrix &rhs) {
	return this->for_each(rhs, addElement);
}

// retour par copy
Matrix Matrix::add(const Matrix& rhs) const {
   Matrix tmp(*this, max(M, rhs.M), max(N, rhs.N));
	return tmp.add(rhs);;
}

// Cree une nouvelle matrice
Matrix* Matrix::addDynamic(const Matrix& rhs) const {
   Matrix* tmp = new Matrix(*this, max(M, rhs.M), max(N, rhs.N));
   return &(tmp->add(rhs));
}

// --- SUB ---
// Modifie la matrice
Matrix& Matrix::sub(const Matrix &rhs) {
   return this->for_each(rhs, subElement);
}

// retour par copy
Matrix Matrix::sub(const Matrix& rhs) const {
   Matrix tmp(*this, max(M, rhs.M), max(N, rhs.N));
   return tmp.sub(rhs);
}

// Cree une nouvelle matrice
Matrix* Matrix::subDynamic(const Matrix& rhs) const {
   Matrix* tmp = new Matrix(*this, max(M, rhs.M), max(N, rhs.N));
   return &(tmp->sub(rhs));
}

// --- MULTYPLY ---
// Modifie la matrice
Matrix& Matrix::multiply(const Matrix &rhs) {
   return this->for_each(rhs, multiplyElement);;
}

// retour par copy
Matrix Matrix::multiply(const Matrix& rhs) const {
   Matrix tmp(*this, max(M, rhs.M), max(N, rhs.N));
   return tmp.multiply(rhs);
}

// Cree une nouvelle matrice
Matrix* Matrix::multiplyDynamic(const Matrix& rhs) const {
   Matrix* tmp = new Matrix(*this, max(M, rhs.M), max(N, rhs.N));
   return &(tmp->multiply(rhs));
}

Matrix& Matrix::for_each(const Matrix& rhs, int (*f)(int, int)) {
   // todo demander assistant precision
   if (rhs.M > M || rhs.N > N)
      throw runtime_error("Cant fit result in matrix");
   // Verification du module n
   if(MODULUS != rhs.MODULUS)
      throw invalid_argument("n modules don't match");

   // Applique le calcul dans une plage incluse dans les deux matrices
	for (size_t i = 0; i < min(M, rhs.M); ++i) {
      for (size_t j = 0; j < min(N, rhs.N); ++j)
         tab[i][j] = f(tab[i][j], rhs.tab[i][j]) % MODULUS;
	}
   return *this;
}











