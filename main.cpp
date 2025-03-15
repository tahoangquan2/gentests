#include <iostream>
#include "gentests.h"

typedef long long ll;

int main() {
  clock_t tStart = clock();
  _set_seed();

  ll l = 1, r = 1e18, x;
  for (int i = 1; i <= 100000000; ++i) {
    x = _get_range(l, r);
  }
  std::cout << x << "\n";

  std::cout << (double)(clock() - tStart) / CLOCKS_PER_SEC;
  return 0;
}
