#include <iostream>

inline bool is_prime(int n) {
  if(n < 2) {
    return false;
  }
  if(n <= 3) {
    return true;
  }
  if(n % 2 == 0 || n % 3 == 0) {
    return false;
  }
  for(int i=5; i*i<=n; i+=6) {
    if(n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

inline long long bin_sqrt(long long x) {
  long long l = 0, r = x;
  while(l < r) {
    long long mid = (l + r + 1ll) >> 1ll;
    if(mid <= x / mid) {
      l = mid;
    } else {
      r = mid - 1ll;
    }
  }
  return l;
} 

inline void solve() {
  long long n;
  std::cin >> n;
  long long sq = bin_sqrt(n);
  if(sq * sq == n && is_prime(sq)) {
    std::cout << "YES\n";
  }
  else {
    std::cout << "NO\n";
  }
  return ;
}

signed main() {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}