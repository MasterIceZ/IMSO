#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 300030;
const ll INF = 1e18 + 100ll;

ll a[MxN], b[MxN], pref_sum[MxN], dp[MxN];

inline void solve() {
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    pref_sum[i] = pref_sum[i - 1] + a[i];
    dp[i] = INF;
  }
  for(int i=1; i<=m; ++i) {
    cin >> b[i];
  }
  if(*max_element(a + 1, a + n + 1) > b[1]) {
    cout << "-1\n";
    return ;
  }
  dp[0] = 0;
  for(int j=1; j<=m; ++j) {
    for(int i=1; i<=n; ++i) {
      ll w = pref_sum[i] - b[j];
      int idx = upper_bound(pref_sum + 1, pref_sum + i + 1, w) - (pref_sum);
      if(pref_sum[i] - pref_sum[idx - 1] <= b[j]) {
        idx--;
      }
      dp[i] = min(dp[i], dp[idx] + m - j);
    }
  }
  cout << dp[n] << "\n";
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