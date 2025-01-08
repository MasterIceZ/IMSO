#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

ll a[MxN];
int dp[MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  ll sum = 0ll;
  dp[0] = 0;
  map<ll, int> mem;
  mem[0] = 0;
  for(int i=1; i<=n; ++i) {
    sum += a[i];
    if(mem.find(sum) != mem.end()) {
      dp[i] = max(dp[i - 1], dp[mem[sum]] + 1);
    }
    else {
      dp[i] = dp[i - 1];
    }
    mem[sum] = i;
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