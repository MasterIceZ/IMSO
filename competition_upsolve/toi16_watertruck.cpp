#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(false)->ios::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  for(int i=1; i<=m; ++i) {
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
    deg[u]++, deg[v]++;
  }
  return 0;
}