#include <iostream>
#include "Matrix.h"

using namespace std;
int main() {

   Matrix a(3,3,1000);
   Matrix b(3,3,1000);
   a.add(b);
   a.multiply(b);
   a.sub(b);

   cout << a;
	return 0;
}
