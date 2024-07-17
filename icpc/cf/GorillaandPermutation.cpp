#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for(int i=n; i>m; --i) {
    cout << i << " ";
  }
  for(int i=1; i<=m; ++i) {
    cout << i << " ";
  }
  cout << "\n";
  return ;
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