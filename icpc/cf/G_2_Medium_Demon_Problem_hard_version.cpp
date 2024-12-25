#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

vector<int> adj[MxN];
int in[MxN], dp[MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int u=1, v; u<=n; ++u) {
    cin >> v;
    adj[u].emplace_back(v);
    in[v]++;
    dp[u] = 1;
  }
  queue<int> q;
  for(int i=1; i<=n; ++i) {
    if(in[i] != 0) {
      continue;
    }
    q.emplace(i);
  }
  int answer = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    answer = max(answer, dp[u]);
    for(auto v: adj[u]) {
      dp[v] += dp[u];
      if(--in[v] == 0) {
        q.emplace(v);
      }
    }
  }
  cout << answer + 2 << "\n";
  for(int i=1; i<=n; ++i) {
    adj[i].clear();
    in[i] = 0;
  }
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