#include <iostream>
#include "Matrix.h"

using namespace std;
int main() {


   Matrix a(3,3,1000);
	cout << "a\n" << endl;
   Matrix b(3,3,1000);

	cout << a << endl << endl;
	cout << b << endl;

	a.sub(b);

	cout << "a - b" << endl << a << endl;
	return 0;
}
