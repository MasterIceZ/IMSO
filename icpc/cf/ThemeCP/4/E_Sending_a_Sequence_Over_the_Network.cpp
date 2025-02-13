#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

bool dp[MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    dp[i] = false;
  }
  dp[0] = true;
  for(int i=1, x; i<=n; ++i) {
    cin >> x;
    int l = i - x, r = i + x;
    if(l >= 1) {
      dp[i] |= dp[l - 1];
    }
    if(r <= n) {
      dp[r] |= dp[i - 1];
    }
  }
  cout << (dp[n] ? "YES": "NO") << "\n";
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