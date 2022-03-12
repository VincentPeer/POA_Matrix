#include <iostream>
#include "Matrix.h"

using namespace std;

void printLn(const Matrix& m) {
   m.print();
   cout << endl << endl;
}
int main() {


   // test constructeur normal
   Matrix a(3,3,10);
   printLn(a);

   // test constructeur taille null

   try {
      Matrix b(0, 0, 10);
   } catch (runtime_error e) {
      cout << e.what() << endl;
   }

   // Test ope simple
   Matrix* c = a.addDynamic(a);
   printLn(*c); // ope ok modulo ok
   delete c;

   // Test ope taille differente
   cout << endl << "3)" << endl;
   Matrix d(4,4,10);
   printLn(d);
   c = d.addDynamic(a);
   printLn(*c); // valeurs extra pas touchee
   delete c;
   c = a.addDynamic(d);
   printLn(*c);
   delete c;

   // test modulo different
   try {
      printLn(a.addToCpy(Matrix(3, 3, 2)));
   } catch (runtime_error e) {
      cout << e.what() << endl;
   }

	return 0;
}
