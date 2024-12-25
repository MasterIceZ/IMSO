#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18 + 100;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  ll a, b;
  cin >> n >> a >> b;
  array<ll, 2> v = {n, n};
  while(__gcd(v[0], a) != 1ll) {
    v[0]--;
  }
  while(__gcd(v[1], b) != 1ll) {
    v[1]--;
  }
  
  vector<vector<ll>> dp(n - v[0] + 2, vector<ll> (n + v[1] + 2, INF));
  dp[0][1] = dp[1][0] = 0ll;
  for(int i=v[0]; i<=n; ++i) {
    for(int j=v[1]; j<=n; ++j) {
      int x = i - v[0] + 1, y = j - v[1] + 1;
      dp[x][y] = min(dp[x - 1][y], dp[x][y - 1]) + __gcd((ll) i, a) + __gcd((ll) j, b);
    }
  }
  ll answer = v[0] + v[1] - 4ll;
  for(int i=1; i<=v[0]; ++i) {
    answer += __gcd((ll) i, a);
  }
  for(int j=1; j<=v[1]; ++j) {
    answer += __gcd((ll) j, b);
  }
  cout << answer + dp[n - v[0] + 1][n - v[1] + 1] << "\n";
  return 0;
}