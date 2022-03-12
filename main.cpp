#include <iostream>
#include "Matrix.h"

using namespace std;
int main() {


   // test constructeur normal
   Matrix a(3,3,10);
	cout << "a\n" << a << endl;

   // test constructeur taille null
   try {
      Matrix b(0, 0, 10);
   } catch (runtime_error e) {
      cout << e.what() << endl;
   }

   // Test ope simple;
   Matrix* c = a.addDynamic(a);
   c->print();

	return 0;
}
