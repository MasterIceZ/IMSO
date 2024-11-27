#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

inline void solve() {
  int n;
  ll x, a;
  cin >> n >> x;
  vector<ll> pref_sum(n + 1), dp(n + 2);
  for(int i=1; i<=n; ++i) {
    cin >> a;
    pref_sum[i] = pref_sum[i - 1] + a;
  }
  for(int i=n-1; i>=0; --i) {
    int idx = upper_bound(pref_sum.begin(), pref_sum.end(), pref_sum[i] + x) - pref_sum.begin();
    dp[i] = dp[idx] + idx - i - 1;
  }
  cout << accumulate(dp.begin(), dp.end(), 0ll) << "\n";
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