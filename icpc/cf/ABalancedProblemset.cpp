#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int x, n, res = 1;
  cin >> x >> n;
  for(int i=1; i*i<=x; ++i) {
    if(x % i != 0) {
      continue;
    }
    if(x / i >= n) {
      res = max(res, i);
    }
    if(n <= i) {
      res = max(res, x / i);
    }
  }
  cout << res;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}