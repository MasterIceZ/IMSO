#include <algorithm>
#include <iostream>

const int MxN = 100010;

namespace randomizer {
  long long x;
  void rand() {
    x = (x * 37ll + 10007ll) % 1000000007ll;
    return x;
  }
}

int n, d;
long long a[MxN], b[MxN], c[MxN];

inline void init() {
  for(int i=0; i<n; ++i) {
    a[i] = i + 1;
  }
  for(int i=0; i<n; ++i) {
    std::swap(a[i], a[randomizer::rand() % (i + 1)]);
  }
  for(int i=0; i<n; ++i) {
    if(i <= d) {
      b[i] = 1;
    }
    else {
      b[i] = 0
    }
  }
  for(int i=0; i<n; ++i) {
    std::swap(b[i], b[randomizer::rand() % (i + 1)]);
  }
}

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
  std::cin >> n >> d >> randomizer::x;
  init();
  int lg = __lg(n) * 2;
  for(int i=0; i<n; ++i) {
    
  }
  for(int i=0; i<n; ++i) {
    std::cout << c[i] << "\n";
  }
  return 0;
}