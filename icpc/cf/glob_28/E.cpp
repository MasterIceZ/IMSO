#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n, m;
  cin >> n >> m;
  n = n + n;
  if(m >= n) {
    cout << "NO\n";
    return ;
  }
  cout << "YES\n";
  // wtf
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