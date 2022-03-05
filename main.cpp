#include <iostream>
#include "Matrix.h"
int main() {

   Matrix a(10,10,1000);
   Matrix b(10,10,1000);
   a.add(b);
   a.multiply(b);
   a.sub(b);

	return 0;
}
