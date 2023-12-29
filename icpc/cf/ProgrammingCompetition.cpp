#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;

int sz[MxN], dp[MxN];
vector<int> adj[MxN];

void dfs(int u) {
  sz[u] = dp[u] = 0;
  for(auto x: adj[u]) {
    dfs(x);
    sz[u] += sz[x];
  }
  for(auto x: adj[u]) {
    dp[u] = max(dp[u], dp[x] - (sz[u] - sz[x]));
  }
  dp[u]++, sz[u]++;
}

inline void solve() {
  int n;
  cin >> n;
  for(int i=2, x; i<=n; ++i) {
    cin >> x;
    adj[x].emplace_back(i);
  }
  dfs(1);
  cout << (n - dp[1]) / 2;
  for(int i=1; i<=n; ++i) {
    adj[i].clear();
  }
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