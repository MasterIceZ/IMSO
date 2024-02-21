#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

vector<int> adj[MxN];
int dp[3][MxN];
string s;

void dfs(int u, int p) {
  
  for(auto x: adj[u]) {
    if(x == p) {
      continue;
    }
    dfs(x, u);
    dp[0][u] += min(dp[0][x], dp[1][x] + 1);
    dp[1][u] += min(dp[0][x] + 1, dp[1][x]);
  }
}

inline void solve() {
  int n;
  cin >> n;
  for(int i=2, p; i<=n; ++i) {
    cin >> p;
    adj[p].emplace_back(i);
    adj[i].emplace_back(p);
  }
  cin >> s;
  s = " " + s;
  for(int i=1; i<=n; ++i) {
    if (s[i] == 'S') {
      dp[0][i] = 0;
      dp[1][i] = 1e9 + 100;
    }
    else if (s[i] == 'P') {
      dp[0][i] = 1e9 + 100;
      dp[1][i] = 0;
    }
    else {
      dp[0][i] = 0;
      dp[1][i] = 0;
    }
  }
  dfs(1, 0);
  cout << min(dp[0][1], dp[1][1]);
  for(int i=1; i<=n; ++i) {
    adj[i].clear();
  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}