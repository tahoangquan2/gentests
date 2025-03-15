#include <iostream>
#include "gentests.h"

using namespace std;
typedef long long ll;

int main() {
  clock_t tStart = clock();
  _set_seed();

  for (int i = 1; i <= 100; ++i) {
    cout << _get_range_prime(1, 1e9) << "\n";
  }

  cout << "\nTime: " << (double)(clock() - tStart) / CLOCKS_PER_SEC;
  return 0;
}
