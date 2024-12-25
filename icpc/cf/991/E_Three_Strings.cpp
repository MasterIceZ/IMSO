#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1010;

int dp[MxN][MxN];

inline void solve() {
  string a, b, c;
  cin >> a >> b >> c;
  int n = (int) a.size(), m = b.size();
  a = " " + a, b = " " + b, c = " " + c;
  for(int i=1; i<=n; ++i) {
    dp[i][0] = dp[i - 1][0] + (a[i] != c[i]);
  }
  for(int i=1; i<=m; ++i) {
    dp[0][i] = dp[0][i - 1] + (b[i] != c[i]);
  }
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      dp[i][j] = min(dp[i - 1][j] + (a[i] != c[i + j]), dp[i][j - 1] + (b[j] != c[i + j]));
    }
  }
  cout << dp[n][m] << "\n";
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