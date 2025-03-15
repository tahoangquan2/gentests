#include <map>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

const long long N = 1e6 + 5;
const long long LIM = (1ll << 15) - 1;
const int PRIME = 1e3;

std::random_device rd;
std::mt19937_64 gen;
std::uniform_int_distribution<long long> rng(0, 1);

long long cache_l, cache_r;
int per[N];
std::map<std::pair<int, int>, bool> flag;

// Set seed for random number generator
void _set_seed() {
  gen.seed(rd());
}

// Get a random number in [l, r]
long long _get_range(long long l, long long r) {
  if (cache_l != l || cache_r != r) {
    cache_l = l;
    cache_r = r;
    rng = std::uniform_int_distribution<long long>(l, r);
  }
  return rng(gen);
}

// Get a random number in [l, r] with random number of digits
long long _get_range_digit(long long l, long long r) {
  long long val = powl(2, (long double)(63.0) / (long double)(LIM) * (long double)(_get_range(0, LIM)));

  return l + val % (r - l + 1);
}

// Shuffle vector
template<class T>
void _shuffle_vector(std::vector<T>& v) {
  shuffle(v.begin(), v.end(), gen);
}

// Shuffle vector with range [l, r)
template<class T>
void _shuffle(std::vector<T>& v, int l = 0, int r = -1) {
  if (!~r) {
    r = v.size();
  }

  if (l == 0 && r == v.size()) {
    _shuffle_vector(v);
    return;
  }

  std::vector<T> t;
  for (int i = l; i < r; ++i) {
    t.push_back(v[i]);
  }

  _shuffle_vector(t);
  for (int i = l; i < r; ++i) {
    v[i] = t[i - l];
  }
}

// Shuffle array with range [l, r]
template<class T>
void _shuffle(T* v, int n, int l = 1, int r = -1) {
  if (!~r) {
    r = n;
  }

  std::vector<T> t;
  for (int i = l; i <= r; ++i) {
    t.push_back(v[i]);
  }

  _shuffle_vector(t);
  for (int i = l; i <= r; ++i) {
    v[i] = t[i - l];
  }
}

// Get a random permutation
void _get_permutation(int n) {
  for (int i = 1; i <= n; ++i) {
    per[i] = i;
  }
  _shuffle(per, n);
}

// Get a random tree
template<class T>
void _get_tree(std::vector<std::pair<T, T>>& e, int n, int d) {
  T x, y;

  for (int i = 2; i <= n; ++i) {
    x = per[i];
    y = per[_get_range(std::max(1, i - d), i - 1)];
    if (_get_range(0, 1)) {
      std::swap(x, y);
    }
    flag[std::make_pair(std::min(x, y), std::max(x, y))] = true;
    e.push_back(std::make_pair(x, y));
  }
}

// Get a random graph with d is the depth level
template<class T>
void _get_graph(std::vector<std::pair<T, T>>& e, int n, int m, int d = N) {
  T x, y;
  std::pair<T, T> p;
  e.clear();
  flag.clear();

  _get_permutation(n);
  _get_tree(e, n, d);

  for (int i = n; i <= m; ++i) {
    do {
      x = _get_range(1, n);
      y = _get_range(1, n);
      p = std::make_pair(std::min(x, y), std::max(x, y));
    } while(x == y || flag.find(p) != flag.end());
    flag[p] = true;
    e.push_back(std::make_pair(x, y));
  }

  _shuffle(e);
}

// Calculate power
long long _power(long long a, long long b, long long m) {
  long long val = 1;
  a %= m;

  while (b) {
    if (b & 1) {
      (val *= a) %= m;
    }
    (a *= a) %= m;
    b >>= 1;
  }

  return val;
}

// Miller Rabin test for prime check
bool _miller_test(long long d, long long n, long long a) {
  long long x = _power(a, d, n);
  if (x == 1 || x == n - 1) {
    return true;
  }

  while (d != n - 1) {
    (x *= x) %= n;
    d <<= 1;
    if (x == 1) {
      return false;
    }
    if (x == n - 1) {
      return true;
    }
  }

  return false;
}

// Check if it is a prime number
bool _check_prime(int n) {
  if (n < 2) {
    return false;
  }
  if (n == 2 || n == 3) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }

  int d = n - 1;
  while (!(d & 1)) {
    d >>= 1;
  }

  int bases[3] = {2, 7, 61};
  for (int a : bases) {
    if (n == a) {
      return true;
    }
    if (!_miller_test(d, n, a)) {
      return false;
    }
  }

  return true;
}

// Get a random prime number in range [l, r]
int _get_range_prime(int l, int r) {
  int cnt = PRIME, x;

  while (cnt--) {
    x = _get_range(l, r);
    if (_check_prime(x)) {
      return x;
    }
  }

  return -1;
}

// Define for shorter access
#define _ss _set_seed
#define _gr _get_range
#define _grd _get_range_digit
#define _grp _get_range_prime
#define _s _shuffle
#define _gg _get_graph
