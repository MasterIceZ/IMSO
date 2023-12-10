#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 220;

int n;
ll x, y, dp[MxN][MxN], a[MxN], sum[MxN];

ll DP(int l, int r) {
  if(dp[l][r] != 0ll) {
    return dp[l][r];
  }
  if(l > r) {
    return dp[l][r] = 1e18 + 100;
  }
  ll res = 1e18 + 100ll;
  ll tot = x + y - (sum[l - 1] - sum[0] + sum[n] - sum[r]);
  res = min(max(a[l], tot - DP(l + 1, r) + 1), max(a[r], tot - DP(l, r - 1) + 1));
  return dp[l][r] = res;
}

void solve() {
  cin >> n >> x >> y;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  memset(dp, 0ll, sizeof dp);
  cout << (DP(1, n) <= x ? "Haros": "Iwys");
}

int main() {
  // cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}