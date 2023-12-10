#include <bits/stdc++.h>

using namespace std;

const int MxN = 330;

struct max_bipartite_matching {
  vector<int> match, adj[MxN];
  vector<bool> seen;
  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
  }
  bool try_match(int u) {
    for(auto x: adj[u]) {
      if(seen[x]) {
        continue;
      }
      seen[x] = true;
      if(match[x] == -1 || try_match(match[x])) {
        match[x] = u;
        return true;
      }
    }
    return false;
  }
  int max_matching(int n) {
    int res = 0;
    match.assign(n + 1, -1);
    for(int u=1; u<=n; ++u) {
      seen.assign(n + 1, false);
      res += try_match(u);
    }
    return res;
  }
} mbm;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  int n, m, u, v;
  cin >> n >> m;
  for(int i=1; i<=m; ++i) {
    cin >> u >> v;
    mbm.add_edge(u, v);
  }
  cerr << mbm.max_matching(n) << "\n";
  cout << n + m - mbm.max_matching(n) * 2;
  return 0;
}
