#include <iostream>
#include "Matrix.h"

using namespace std;
int main() {


   // test constructeur normal
   Matrix a(3,3,10);
	cout << "a\n" << a << endl;

   // test constructeur taille null
   Matrix b(-1,0,10);
   cout << "b\n" << b << endl;

	return 0;
}
