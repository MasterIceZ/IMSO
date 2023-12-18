#include <bits/stdc++.h>

using namespace std;

// dp(i) = number of operation in range i to n

inline void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 2), dp(n + 2, n);
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  dp[n] = 1;
  auto calc = [&](int idx) {
    if(idx > n + 1) {
      return n;
    }
    if(idx == n + 1) {
      return 0;
    }
    return dp[idx];
  };
  for(int i=n-1; i>=1; --i) {
    dp[i] = min(dp[i + 1] + 1, calc(i + a[i] + 1));
  }
  cout << dp[1];
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