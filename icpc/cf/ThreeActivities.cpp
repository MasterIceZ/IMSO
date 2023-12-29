#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int n;
ll a[5][MxN], dp[5][MxN];

inline void solve() {
  cin >> n;
  vector<int> v;
  for(int i=1; i<=3; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> a[i][j];
    }
    v.emplace_back(i);
  }
  ll res = 0;
  do {
    dp[1][1] = a[v[0]][1];
    dp[1][2] = max(dp[1][1], a[v[0]][2]);
    dp[2][2] = dp[1][1] + a[v[1]][2];
    for(int i=3; i<=n; ++i) {
      dp[1][i] = max(dp[1][i - 1], a[v[0]][i]);
      dp[2][i] = max(dp[2][i - 1], dp[1][i - 1] + a[v[1]][i]);
      dp[3][i] = max(dp[3][i - 1], dp[2][i - 1] + a[v[2]][i]);
    }
    res = max({res, dp[1][n], dp[2][n], dp[3][n]});
  } while(next_permutation(v.begin(), v.end()));
  cout << res;
  return ;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}