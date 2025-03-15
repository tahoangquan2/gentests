#include <iostream>
#include "gentests.h"

using namespace std;
typedef long long ll;

int main() {
  clock_t tStart = clock();
  _set_seed();

  int a[15];
  for(int i = 1; i <= 10; ++i) {
    a[i] = i;
  }
  for(int i = 1; i <= 10; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
  _shuffle(a, 10);
  for(int i = 1; i <= 10; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
  _shuffle(a, 10, 3, 6);
  for(int i = 1; i <= 10; ++i) {
    cout << a[i] << " ";
  }

  cout << "\nTime: " << (double)(clock() - tStart) / CLOCKS_PER_SEC;
  return 0;
}
