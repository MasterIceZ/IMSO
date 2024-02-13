#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 110;
const int MxW = 100010;

int wei[MxN];
ll dp[MxN][MxW], val[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, w;
  cin >> n >> w;
  for(int i=1; i<=n; ++i) {
    cin >> wei[i] >> val[i];
  }
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=w; ++j) {
      if(j < wei[i]) {
        dp[i][j] = dp[i - 1][j];
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wei[i]] + val[i]);
      }
    }
  }
  cout << dp[n][w] << "\n";
  return 0;
}