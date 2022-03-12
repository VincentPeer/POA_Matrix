//
// Created by dimde on 2/24/2022.
//

#include "Matrix.h"
#include "RandUnsigned.h"
#include <algorithm>
#include <cstring>

using namespace std;

// ---- operations
int multiplyElement(int a, int b) {
   return a * b;
}

int subElement(int a, int b) {
   return a - b;
}

int addElement(int a, int b) {
   return a + b;
}

// Constructeur nouvelle matrice
Matrix::Matrix(size_t M, size_t N, unsigned n)  : M(M), N(N), modulus(n) {
   if (M < 1 || N < 1 || n < 1)
      throw runtime_error("Params must be greater than 0");

	allocate();
	// Ajout de valeurs aléatoire
	RandUnsigned& rand = RandUnsigned::getInstance();
	for (size_t i = 0; i < M; ++i)
		for (size_t j = 0; j < N; ++j)
			tab[i][j] = rand.getUnsigned(modulus);
}

// Constructeur de copie, renvoie juste le travail au constructeur copie spécialisé
Matrix::Matrix(const Matrix &matrix) : Matrix(matrix, matrix.M, matrix.N) {}

// Constructeur de copie spécialisé
Matrix::Matrix(const Matrix &matrix, size_t M, size_t N) : M(M), N(N), modulus(matrix.modulus) {
   if (M < matrix.M || N < matrix.N)
      throw runtime_error("Given sizes are too small");
   allocate();
   copyTab(matrix);
}

void Matrix::allocate() {
	tab = new int*[M];
	for (size_t i = 0; i < M; ++i)
      tab[i] = new int[N];
}

void Matrix::copyTab(const Matrix &matrix) {
   // Copie des valeurs
   for (size_t i = 0; i < matrix.M; ++i) {
      memcpy(tab[i], matrix.tab[i], matrix.N* sizeof(int));
      // Mise des valeurs à 0 si ce tableau a plus de colonnes
      memset(tab[i] + matrix.N, 0, (N - matrix.N) * sizeof(int));
   }
   // Mise des valeurs à 0 si ce tableau est plus grand
   for (size_t i = matrix.M; i < M; ++i)
      memset(tab[i], 0, N * sizeof(int));
}

Matrix::~Matrix() {
   deleteTab();
}

void Matrix::deleteTab() {
   for (size_t i = 0; i < M; ++i)
      delete[] tab[i];
   delete[] tab;
}

Matrix &Matrix::operator=(const Matrix &matrix) {
   if (&matrix != this) {
      modulus = matrix.modulus;
      if (M != matrix.M || N != matrix.N) {
         deleteTab();
         M = matrix.M;
         N = matrix.N;
         allocate();
      }
      copyTab(matrix);
   }
   return *this;
}


ostream& operator<<(ostream& stream, const Matrix& matrix) {
   for (size_t i = 0;  i < matrix.M; ++i) {
      if (i) cout << endl; // Pas la 1ere itération
      for (size_t j = 0; j < matrix.N; ++j) {
         if (j) cout << " "; // Pas la 1ere itération
         cout << matrix.tab[i][j];
      }
   }
	return stream;
}

// --- ADD ---
// Modifie la matrice
Matrix& Matrix::add(const Matrix &rhs) {
	return this->for_each(rhs, addElement);
}

// retour par copie
Matrix Matrix::addToCpy(const Matrix& rhs) const {
   Matrix tmp(*this, max(M, rhs.M), max(N, rhs.N));
	return tmp.add(rhs);
}

// Crée une nouvelle matrice
Matrix* Matrix::addDynamic(const Matrix& rhs) const {
   Matrix* tmp = new Matrix(*this, max(M, rhs.M), max(N, rhs.N));
   return &(tmp->add(rhs));
}

// --- SUB ---
// Modifie la matrice
Matrix& Matrix::sub(const Matrix &rhs) {
   return this->for_each(rhs, subElement);
}

// retour par copie
Matrix Matrix::sub(const Matrix& rhs) const {
   Matrix tmp(*this, max(M, rhs.M), max(N, rhs.N));
   return tmp.sub(rhs);
}

// Crée une nouvelle matrice
Matrix* Matrix::subDynamic(const Matrix& rhs) const {
   Matrix* tmp = new Matrix(*this, max(M, rhs.M), max(N, rhs.N));
   return &(tmp->sub(rhs));
}

// --- MULTYPLY ---
// Modifie la matrice
Matrix& Matrix::multiply(const Matrix &rhs) {
   return this->for_each(rhs, multiplyElement);;
}

// retour par copie
Matrix Matrix::multiply(const Matrix& rhs) const {
   Matrix tmp(*this, max(M, rhs.M), max(N, rhs.N));
   return tmp.multiply(rhs);
}

// Crée une nouvelle matrice
Matrix* Matrix::multiplyDynamic(const Matrix& rhs) const {
   Matrix* tmp = new Matrix(*this, max(M, rhs.M), max(N, rhs.N));
   return &(tmp->multiply(rhs));
}

Matrix& Matrix::for_each(const Matrix& rhs, int (*f)(int, int)) {
   if (rhs.M > M || rhs.N > N)
      throw runtime_error("Can't fit result in matrix");
   // Verification du module n
   if(modulus != rhs.modulus)
      throw invalid_argument("n modules don't match");

   // Applique le calcul dans une plage incluse dans les deux matrices
	for (size_t i = 0; i < min(M, rhs.M); ++i) {
      for (size_t j = 0; j < min(N, rhs.N); ++j)
         tab[i][j] = f(tab[i][j], rhs.tab[i][j]) % modulus;
	}
   return *this;
}

















