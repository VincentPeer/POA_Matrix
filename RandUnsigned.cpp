//
// Created by dimde on 3/11/2022.
//

#include <cstdlib>
#include "RandUnsigned.h"

RandUnsigned::RandUnsigned() {
   srand(1);
}

RandUnsigned& RandUnsigned::getInstance() {
   static RandUnsigned instance;
   return instance;
}

int RandUnsigned::getUnsigned(unsigned max) {
   return rand() / (RAND_MAX + 1.) * max;
}
