#include <iostream>
#include "gentests.h"

using namespace std;
typedef long long ll;

int main() {
  clock_t tStart = clock();
  _set_seed();

  int n = 10;
  vector<pair<int,int>> a;
  _get_tree(a, n);
  for(pair<int,int> x : a) {
    cout << x.first << " " << x.second << "\n";
  }
  cout << "---\n";
  _get_tree(a, n, 1);
  for(pair<int,int> x : a) {
    cout << x.first << " " << x.second << "\n";
  }

  cout << "\nTime: " << (double)(clock() - tStart) / CLOCKS_PER_SEC;
  return 0;
}
