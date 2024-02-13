#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> h(n + 1), dp(n + 1, 1e9 + 100);
  for(int i=1; i<=n; ++i) {
    cin >> h[i];
  }
  dp[0] = 0;
  dp[1] = 0;
  for(int i=2; i<=min(n, k-1); ++i) {
    dp[i] = abs(h[1] - h[i]);
  }
  for(int i=k; i<=n; ++i) {
    for(int j=1; j<=k; ++j) {
      dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }
  }
  cout << dp[n];
  return 0;
}