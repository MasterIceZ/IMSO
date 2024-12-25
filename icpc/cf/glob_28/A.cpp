#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n;
  cin >> n;
  cout << (n % 33 == 0 ? "YES": "NO") << "\n";
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}