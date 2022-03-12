//
// Created by dimde on 2/24/2022.
//

#ifndef POA_MATRIX_MATRIX_H
#define POA_MATRIX_MATRIX_H

#include <algorithm>
#include <iostream>


class Matrix {
   size_t M, N;
   unsigned modulus;
   int** tab{};

   /**
    * Allocation de la mémoire de tab
    */
   void allocate();

   /**
    * Copie les valeurs d'un tableau
    * @param matrix la matrice qui contient le tableau à copier
    */
   void copyTab(const Matrix& matrix);

   /**
    * libère la mémoire réservée pour le tableau
    */
   void deleteTab();

   /**
    * Opérateur d'écriture sur un flux
    * @param stream le flux sur lequel écrire
    * @param matrix la matrice
    * @return une référence sur le flux
    */
	friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);

	/**
	 * Applique la fonction f entre chaque éléments correspondants des tableaux et insert le résultat
	 * dans le tableau
	 * @param rhs operand gauche
	 * @param f la fonction définissant opération a effectuer
	 * @return le tableau modifier
	 */
	Matrix& for_each(const Matrix& rhs, int (*f)(int a, int b));

	/**
	 * Constructeur de copie avec une valeur N et/ou M plus grande que celle de la matrice à copier
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
    * @param matrix la matrice à copier
    * @return une référence sur la matrice modifiée
    */
   Matrix& operator=(const Matrix& matrix);

   // -- ADD ---
   /**
    * Additionne les valeurs de 2 matrices
    * @param rhs la 2e matrice
    * @return une référence sur la matrice modifiée
    */
	Matrix& add(const Matrix& rhs);

	/**
	 * Additionne les valeurs de deux matrices et retourne le résultat par copie
	 * @param rhs la 2e matrice
	 * @return la matrice résultante par copie
	 */
	Matrix addToCpy(const Matrix& rhs) const;

   /**
    * Additionne les valeurs de deux matrices et retourne le résultat dans une matrice crée dynamiquement
    * @param rhs la 2e matrice
    * @return un pointeur sur la matrice résultante
    */
	Matrix* addDynamic(const Matrix& rhs) const;
	// --- SUB

   /**
    * Soustrait les valeurs de la 2 matrices
    * @param rhs la 2e matrice
    * @return une référence sur la matrice modifiée
    */
   Matrix& sub(const Matrix& rhs);

   /**
	 * Soustrait les valeurs de la 2e matrices à celle-ci et retourne le résultat par copie
	 * @param rhs la 2e matrice
	 * @return la matrice résultante par copie
	 */
   Matrix sub(const Matrix& rhs) const;

   /**
   * Soustrait les valeurs de la 2e matrices à celle-ci et retourne le résultat dans une matrice crée dynamiquement
   * @param rhs la 2e matrice
   * @return un pointeur sur la matrice résultante
   */
   Matrix* subDynamic(const Matrix& rhs) const;

   // --- MULTYPLY ---

   /**
   * Mutliplie les valeurs de la 2e matrice a celle-ci
   * @param rhs la 2e  matrice
   * @return une référence sur la matrice modifiée
   */
   Matrix& multiply(const Matrix& rhs);

   /**
	 * Mutliplie les valeurs de deux matrices et retourne le résultat par copie
	 * @param rhs la 2e matrice
	 * @return la matrice résultante par copie
	 */
   Matrix multiply(const Matrix& rhs) const;

   /**
    * Mutliplie les valeurs de deux matrices et retourne le résultat dans une matrice crée dynamiquement
    * @param rhs la 2e matrice
    * @return un pointeur sur la matrice résultante
    */
   Matrix* multiplyDynamic(const Matrix& rhs) const;

   /**
    * Prints the matrix
    */
   void print() const;

};


#endif //POA_MATRIX_MATRIX_H
