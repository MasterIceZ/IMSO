#include <algorithm>
#include <iostream>

const int MxN = 110;

int n;
long long a[MxN], h;

inline bool ok(long long mid) {
  long long sum = mid;
  for(int i=2; i<=n; ++i) {
    sum += std::min(mid, a[i] - a[i - 1]);
  }
  return (sum >= h);
}

inline void solve() {
  std::cin >> n >> h;
  for(int i=1; i<=n; ++i) {
    std::cin >> a[i];
  }
  long long l = 1ll, r = 1e18 + 100ll;
  while(l < r) {
    long long mid = (l + r) >> 1ll;
    if(ok(mid)) {
      r = mid;
    }
    else {
      l = mid + 1ll;
    }
  }
  std::cout << l << "\n";
  return ;
}

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}