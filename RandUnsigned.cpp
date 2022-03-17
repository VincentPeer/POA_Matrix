#include <cstdlib>
#include <ctime>
#include "RandUnsigned.h"
RandUnsigned::RandUnsigned() {
   srand(time(nullptr));
}

RandUnsigned& RandUnsigned::getInstance() {
   static RandUnsigned instance;
   return instance;
}

unsigned RandUnsigned::getUnsigned(unsigned max) {
   return rand() / (RAND_MAX + 1.) * max;
}
