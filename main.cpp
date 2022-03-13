#include <iostream>
#include "Matrix.h"

using namespace std;

void printLn(const Matrix& m, string title = "") {
    cout << (title != "" ? title.append("\n") : "") ;
    m.print();
    cout << endl << endl;
}
int main() {

    // Construction d'une matrice
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



    // Opérations simples
    cout << "Matrix simple operations" << endl;

    a1.add(a2); // a1 = ...
    printLn(a1, "a1 + a2 using add");

    Matrix r1 = a1.subToCpy(a2);
    printLn(a1, "a1 - a2 using subToCpy");

    Matrix* r2 = a1.multiplyDynamic(a2);
    printLn(*r2, "a1 * a2 using multiplyDynamic");
    delete r2;



    // Opérations avec Matrices de taille différentes
    cout << "Matrix operations using different matrix sizes" << endl;

    unsigned mod = 10;
    cout << "The modulus is " << mod << endl;
    Matrix d1(5, 4, mod);
    printLn(d1, "d1");
    Matrix d2(2,2,mod);

    r2 = d1.addDynamic(d2);
    printLn(*r2, "d1 + d2 using addDynamic"); // valeurs extra pas touchee
    delete r2;

    r2 = d2.addDynamic(d1);
    printLn(*r2, "d2 + d1 using addDynamic");
    delete r2;

    // Opération avec modulo différent

    // Constructeur avec paramètre(s) nul(s)
    try {
        Matrix a3(0, 0, 10);
    } catch (runtime_error e) {
        cout << e.what() << endl << endl;
    }

    // test modulo different
    try {
        printLn(a1.addToCpy(Matrix(3, 3, 2)));
    } catch (runtime_error e) {
        cout << e.what() << endl;
    }

    return 0;
}
