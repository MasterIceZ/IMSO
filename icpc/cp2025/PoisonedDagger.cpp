#include <algorithm>
#include <iostream>

const int MxN = 110;

int n;
long long a[MxN], h;

inline bool ok(long long mid) {
  long long sum = 0ll;
  for(int i=2; i<=n; ++i) {
    sum += std::min(mid, a[i] - a[i - 1]);
  }
  return (sum >= h);
}