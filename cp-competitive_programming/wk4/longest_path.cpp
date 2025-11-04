#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

const int MxN = 100010;

std::vector<int> adj[MxN];
int in[MxN], dp[MxN];

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  for(int i=1, u, v; i<=m; ++i) {
    std::cin >> u >> v;
    adj[u].emplace_back(v);
    in[v]++;
  }
  std::queue<int> q;
  for(int i=1; i<=n; ++i) {
    if(in[i]) {
      continue;
    }
    dp[i] = 0;
    q.emplace(i);
  }
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto v: adj[u]) {
      dp[v] = std::max(dp[v], dp[u] + 1);
      if(--in[v] == 0) {
        q.emplace(v);
      }
    }
  }
  std::cout << *std::max_element(dp + 1, dp + n + 1) << '\n';
  return 0;
}