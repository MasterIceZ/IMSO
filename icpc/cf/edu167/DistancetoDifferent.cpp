#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353ll;
const int MxN = 200020;
const int MxK = 11;

ll dp[MxK][MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  dp[0][0] = 1ll;
  for(int state=0; state<=k; ++state) {
    ll cur_base = dp[0][max(state - 1, 0)];
    for(int i=1; i<=n; ++i) {
      dp[state][i] = cur_base;
      if(i > 2 && i < n) {
        dp[state][i] = (((dp[state][i] + dp[max(state - 1, 0)][i - 2]) % MOD) + MOD) % MOD;
      }
      cur_base = (cur_base + dp[max(state - 1, 0)][i]) % MOD;
    }
  }
  cout << dp[k][n] << "\n";
  return 0;
}