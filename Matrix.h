//
// Created by dimde on 2/24/2022.
//

#ifndef POA_MATRIX_MATRIX_H
#define POA_MATRIX_MATRIX_H

#include <algorithm>
#include <iostream>

typedef enum {MODIFY, COPY, DYNAMIC} OperationType;

class Matrix {
   size_t N, M;
   unsigned MODULUS;
   int** tab{};

   /**
    * Allocation de la memoire de tab
    */
   void allocate();

   /**
    * Copie les valeurs d'un tableau
    * @param matrix la matrice qui contient le tableau a copier
    */
   void copyTab(const Matrix& matrix);

   /**
    * libere la memoire reservee pour le tableau
    */
   void deleteTab();

   /**
    * Opérateur d'écriture dans un flux
    * @param stream le flux dans lequel écrire
    * @param matrix la matrice
    * @return le flux
    */
	friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);

	/**
	 * Applique la fonction f entre chaque elements correspondants des tableaux et insert le résultat
	 * dans le tableau
	 * @param rhs operand gauche
	 * @param f la fonction définissant opération a effectuer
	 * @return le tableau modifier
	 */
	Matrix& for_each(const Matrix& rhs, int (*f)(int a, int b));

	/**
	 * Constructeur copy avec N et/ou M plus grand que la matrice a copier
	 * @param matrix
	 * @param M
	 * @param N
	 */
	Matrix(const Matrix& matrix, size_t M, size_t N);

public:
   /**
    * Constructeur avec valeurs aléatoires
    * @param N nombre de lignes de la matrice
    * @param M nombre de colones de la matrice
    * @param n valeur max
    */
   Matrix(size_t N, size_t M, unsigned n);

   /**
    * Constructeur par copie
    * @param matrix la matrice a copier
    */
   Matrix(const Matrix& matrix);

   /**
    * Destructeur
    */
   ~Matrix();

   /**
    * Opérateur d'affectation
    * @param matrix la matrice a copier
    * @return reference a la matrice modifiee
    */
   Matrix& operator=(const Matrix& matrix);

   // -- ADD ---
	Matrix& add(const Matrix& rhs);
	Matrix addToCpy(const Matrix& rhs) const;
	Matrix* addDynamic(const Matrix& rhs) const;
	// --- SUB
   Matrix& sub(const Matrix& rhs);
   Matrix sub(const Matrix& rhs) const;
   Matrix* subDynamic(const Matrix& rhs) const;
   // --- MULTYPLY ---
   Matrix& multiply(const Matrix& rhs);
   Matrix multiply(const Matrix& rhs) const;
   Matrix* multiplyDynamic(const Matrix& rhs) const;


};


#endif //POA_MATRIX_MATRIX_H
