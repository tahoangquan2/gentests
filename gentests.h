#include <random>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

std::random_device rd;
std::mt19937_64 gen;
std::uniform_int_distribution<long long> rng(0, 1);

long long cache_l = 0, cache_r = 1;

// Set seed for random number generator
void _set_seed() {
  gen.seed(rd());
  cache_l = 0;
  cache_r = 1;
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
  long long val = powl(2, (long double)(63.0) / (long double)(32767) * (long double)(_get_range(0, 32767)));

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


// Shuffle array with range [l, r)
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
