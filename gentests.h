#include "time.h"
#include "stdlib.h"

const unsigned long long default_seed = (unsigned long long)(time(NULL));

void _set_seed(unsigned long long seed = default_seed) {
  srand(seed);
}
