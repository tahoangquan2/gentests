#include <iostream>
#include "gentests.h"

using namespace std;
typedef long long ll;

int main() {
  clock_t tStart = clock();
  _set_seed();

  vector<int> a;
  for(int i = 1; i <= 10; ++i) {
    a.push_back(i);
  }
  for(int x : a) {
    cout << x << " ";
  }
  cout << "\n";
  _shuffle(a);
  for(int x : a) {
    cout << x << " ";
  }
  cout << "\n";
  _shuffle(a, 3, 6);
  for(int x : a) {
    cout << x << " ";
  }

  cout << "\nTime: " << (double)(clock() - tStart) / CLOCKS_PER_SEC;
  return 0;
}
