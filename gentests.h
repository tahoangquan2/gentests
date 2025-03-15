#include <random>
#include <time.h>
#include <stdlib.h>

std::random_device rd;
std::mt19937_64 gen;
std::uniform_int_distribution<long long> rng(0, 1);

long long cache_l = 0, cache_r = 1;

void _set_seed() {
  gen.seed(rd());
  cache_l = 0;
  cache_r = 1;
}

long long _get_range(long long l, long long r) {
  if (cache_l != l || cache_r != r) {
    cache_l = l;
    cache_r = r;
    rng = std::uniform_int_distribution<long long>(l, r);
  }
  return rng(gen);
}
