#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 110;

int a[MxN << 1];

inline void solve() {
  int n, x;
  cin >> n >> x;
  for(int i=1; i<=2*n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + (2 * n) + 1);
  bool ok = true;
  for(int i=1; i<=n; ++i) {
    ok &= (a[n + i] - a[i] >= x);
  }
  cout << (ok ? "YES": "NO") << "\n";
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