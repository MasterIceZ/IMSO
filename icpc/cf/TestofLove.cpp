#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

int dp[MxN];

inline bool jump_able(char x) {
  return x == 'B' || x == 'L';
}

inline void solve() {
  int n, m, k;
  string s;
  cin >> n >> m >> k >> s;
  s = "B" + s + "B";
  for(int i=1; i<=n+1; ++i) {
    dp[i] = 1e9 + 100;
    if(s[i] == 'C') {
      continue;
    }
    dp[i] = dp[i - 1];
    for(int go_back=1; go_back<=m; ++go_back) {
      if(i - go_back < 0 || !jump_able(s[i - go_back])) {
        continue;
      }
      dp[i] = min(dp[i], dp[i - go_back]);
    }
    dp[i] += (s[i] == 'W');
  }
  cout << (dp[n + 1] <= k ? "YES": "NO") << "\n";
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