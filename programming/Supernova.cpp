#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

vector<pair<int, int>> adj[MxN];
int in[MxN];
ll dp[MxN], answer[MxN];
bitset<MxN> visited;
queue<int> q;

int main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
    in[u]++, in[v]++;
    dp[i] = 1ll;
  }
  for(int i=1; i<=n; ++i) {
    if(in[i] != 1) {
      continue;
    }
    q.emplace(i);
    visited[i] = true;
  }
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(auto [v, idx]: adj[u]) {
      if(visited[v] == true) {
        continue;
      }
      dp[v] += dp[u];
      answer[idx] = dp[u] * ((ll) n - dp[u]);
      if(--in[v] == 1) {
        q.emplace(v);
        visited[v] = true;
      }
    }
  }
  for(int i=1; i<=m; ++i) {
    cout << answer[i] << " ";
  }
  cout << "\n";
  return 0;
}