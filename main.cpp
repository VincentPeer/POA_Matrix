#include <iostream>
#include "Matrix.h"

using namespace std;

void printLn(const Matrix& m, string title = "") {
    cout << (title != "" ? title.append("\n") : "") ;
    m.print();
    cout << endl << endl;
}
int main() {
    unsigned mod = 10;
    cout << "The modulus is " << mod << endl << endl;

    /* -------- Construction d'une matrice -------- */
    cout << "Matrix construction" << endl;

    // Constructeur taille et modulo minimal puis copie
    Matrix b1(1,1,1);
    Matrix b2(b1);
    printLn(b1, "b1 basic constructor");
    printLn(b2, "b2 copy constructor from b1");

    // Constructeur à partir de dimensions et modulo donnés
    Matrix a1(3, 3, 10);
    printLn(a1, "a1 basic constructor");

    // Constructeur de copie
    Matrix a2(a1);
    printLn(a2, "a2 copy constructor from a1");
    /* --------------------------------------------- */


    /* ------------ Opérations simples ------------- */
    cout << "Matrix simple operations" << endl;

    printLn(a1, "ONE"); // Matrices utilisées pour les opérations
    printLn(a2, "TWO");

    a1.add(a2); // a1 = ...
    printLn(a1, "ONE = ONE + TWO using add");

    Matrix r1 = a1.subToCpy(a2);
    printLn(r1, "ONE - TWO using subToCpy");

    Matrix* r2 = a1.multiplyDynamic(a2);
    printLn(*r2, "ONE * TWO using multiplyDynamic");
    delete r2;
    /* --------------------------------------------- */


    /*  Opérations avec Matrices de taille différentes */
    cout << "Matrix operations using different matrix sizes" << endl;

    Matrix d1(5, 4, mod);
    printLn(d1, "ONE");
    Matrix d2(2,2,mod);
    printLn(d2, "TWO");

    r2 = d1.addDynamic(d2);
    printLn(*r2, "ONE + TWO using addDynamic");
    delete r2;

    r2 = d2.addDynamic(d1);
    printLn(*r2, "TWO + ONE using addDynamic");
    delete r2;
    /* --------------------------------------------- */


    /* --------- Opérateur d'affectation ----------- */
    cout << "Assignment operator" << endl;
    printLn(a1, "ONE");
    printLn(a2, "TWO");
    a1 = a2;
    printLn(a1, "a1 = a2");
    /* --------------------------------------------- */


    /* --------- Cas d'exception levée ------------- */
    // Opération avec modulo différent
    try {
       printLn(a1.addToCpy(Matrix(3, 3, 2)));
    } catch (const runtime_error& e) {
       cout << e.what() << endl;
    }

    // Constructeur avec paramètre(s) nul(s)
    try {
        Matrix a3(0, 0, 10);
    } catch (const runtime_error& e) {
        cout << e.what() << endl << endl;
    }
    /* --------------------------------------------- */


    return 0;
}
