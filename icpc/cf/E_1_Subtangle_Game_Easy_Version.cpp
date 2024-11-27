#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using dp_t = vector<vector<int>>;

const int MxN = 330;

int a[MxN], b[MxN][MxN];

inline void solve() {
  int l, n, m;
  cin >> l >> n >> m;
  for(int i=l; i>=1; --i) {
    cin >> a[i];
  }
  for(int i=n; i>=1; --i) {
    for(int j=m; j>=1; --j) {
      cin >> b[i][j];
    }
  }
  dp_t dp(n + 1, vector<int> (m + 1, 0));
  for(int s=1; s<=l; ++s) {
    dp_t new_dp(n + 1, vector<int> (m + 1, 0));
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=m; ++j) {
        if(b[i][j] == a[s]) {
          new_dp[i][j] |= !dp[i - 1][j - 1];
        }
        new_dp[i][j] |= new_dp[i - 1][j];
        new_dp[i][j] |= new_dp[i][j - 1];
      }
    }
    dp = new_dp;
  }
  cout << (dp[n][m] ? "T": "N") << "\n";
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