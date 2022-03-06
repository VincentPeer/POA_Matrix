#include <iostream>
#include "Matrix.h"

using namespace std;
int main() {
	srand(49);

   Matrix a(3,3,1000);
	cout << "a\n" << a << endl;
   Matrix b(3,3,1000);
   a.add(b);
	cout << "a + b" << endl << a << endl;

	a.multiply(b);
	cout << "a x b" << endl << a << endl;

	a.sub(b);

	cout << "a - b" << endl << a << endl;
	return 0;
}
