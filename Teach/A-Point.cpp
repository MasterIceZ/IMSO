#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

const int MxN = 660;
ll a[MxN], qs[MxN], dp[MxN][MxN];

ll DP(int l, int r) {
  if(dp[l][r] != -1) {
    return dp[l][r];
  }
  if(l == r) {
    return dp[l][r] = 0;
  }
  dp[l][r] = -1e18 - 100;
  for (int k = l; k < r; ++k) {
    ll A = min(qs[k] - qs[l - 1], qs[r] - qs[k]);
    ll B = max(qs[k] - qs[l - 1], qs[r] - qs[k]);
    ll new_score = (A << 1ll) + B;
    dp[l][r] = max(dp[l][r], DP(l, k) + DP(k + 1, r) + new_score);
  }
  return dp[l][r];
}

int main()
{
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    qs[i] = qs[i - 1] + a[i];
    // dp[1][1] = a[i];
  }
  // for (int sz = 2; sz <= n; ++sz) {
  //   for (int l = 1; l + sz - 1 <= n; ++l) {
  //     int r = l + sz - 1;
  //     dp[l][r] = -1e18 - 100;
  //     for (int k = l; k < r; ++k)
  //     {
  //       ll minn = min(qs[k] - qs[l - 1], qs[r] - qs[k]);
  //       ll maxx = max(qs[k] - qs[l - 1], qs[r] - qs[k]);
  //       ll score = 2ll * minn + maxx;
  //       dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + score);
  //     }
  //   }
  // }
  // cout << dp[1][n] << "\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = -1;
    }
  }
  cout << DP(1, n) << "\n";
  return 0;
}